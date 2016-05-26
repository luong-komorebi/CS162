#include "Question.h"
#include "Interface.h"
#include <iostream>

std::ifstream in;
std::ofstream out;

Question::Question()
{
	if (in)
	{
		in >> ID;
		in.ignore(10, '\n');
		in.get(subject, 10, '\n');
		in.ignore(10, '\n');
		getline(in, author);
		getline(in, questionIs);
		in >> optionNum;
		in.ignore(10, '\n');
		optArr = new Option[optionNum];
		for (int i = 0; i < optionNum; ++i)
		{
			in.get(optArr[i].option, 50, '\n');
			in.ignore(10, '\n');
		}
		getline(in, answers);
		in >> viewAble;
		in >> multiAns;
		in.ignore(10, '\n');
		next = NULL;
	}
	else
	{

	}
}
Question::~Question()
{}

questionList::questionList()
{
	Question* qCur;
	in.open("inputQuestion");
	if (in)
	{
		if (!in.eof())
		{
			qHead = new Question();
			qCur = qHead;
		}
		while (!in.eof())
		{
			qCur->next = new Question();
			qCur = qCur->next;
		}
		in.close();
	}
}
questionList::~questionList()
{}

void Question::outputQuestion() //show question without answer
{
	cout << "ID : " << ID << endl;
	cout << "Subject: " << subject << endl;
	cout << "Author : " << author << endl;
	cout << "Question is :  " << questionIs << endl;
	cout << "Options :" << endl;
	for (int i = 0; i < optionNum; ++i)
		cout << optArr[i].option << endl;
	if (multiAns == true)
		cout << "You can choose many answers." << endl;
	else
		cout << "You can choose one answer only. " << endl;
	cout << "**************************" << endl;
}
void Question::outputAnswer() //show question with answer
{
	cout << "ID : " << ID << endl;
	cout << "Subject: " << subject << endl;
	cout << "Author : " << author << endl;
	cout << "Question is :  " << questionIs << endl;
	cout << "Options :" << endl;
	for (int i = 0; i < optionNum; ++i)
		cout << optArr[i].option << endl;
	if (multiAns == true)
		cout << "You can choose many answers." << endl;
	else
		cout << "You can choose one answer only. " << endl;
	cout << answers << endl;
	cout << "**************************" << endl;
}

void questionList::outputList()
{
	system("cls");
	gotoxy(0, 0);
	Question* qCur = qHead;
	while (qCur != NULL)
	{
		qCur->outputAnswer();
		qCur = qCur->next;
	}
	system("pause");
}
void questionList::viewQuestion(User* cur)			//Question menu 
{
	Question* qCur = qHead;
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Show all";
	gotoxy(28, 5);
	cout << "2. Search keyword";
	gotoxy(28, 6);
	cout << "3. Search author";
	gotoxy(28, 7);
	cout << "4. Nope, just having some fun wandering";
	switch (keyControl(4))
	{
	case 1:
		system("cls");
		while (qCur != NULL)
		{
			if (cur->checkSubject(qCur->subject))
				qCur->outputAnswer();
			qCur = qCur->next;
		}
		system("pause");
		return;
	case 2:
		searchKeyword(cur);
		return;
	case 3:
		searchAuthor(cur);
		return;
	case 4:
		return;
	default: cout << "Invalid input" << endl;
		Sleep(1000);
		return;
	}
}

void questionList::searchKeyword(User* cur)			//Search question by keyword
{
	Question* qCur = qHead;
	system("cls");
	gotoxy(0, 0);
	int soluong = 0;
	cout << "Input the keyword: ";
	string keyword;
	getline(cin, keyword);
	if (qHead == NULL)
	{
		cout << "No question available";
		return;
	}
	while (qCur != NULL)
	{
		if (qCur->questionIs.find(keyword) != std::string::npos)
		{
			if (cur->checkSubject(qCur->subject))
			{
				qCur->outputAnswer();
				qCur = qCur->next;
				soluong++;
			}
			else
				qCur = qCur->next;
		}
		else
			qCur = qCur->next;
	}
	if (soluong == 0)
		cout << "No question match." << endl;
	system("pause");
}

void questionList::searchAuthor(User* cur)		//Search author by keyword
{
	Question* qCur = qHead;
	system("cls");
	gotoxy(0, 0);
	int soluong = 0;
	cout << "Input author name: ";
	string keyword;
	getline(cin, keyword);
	if (qHead == NULL)
	{
		cout << "No question available";
		return;
	}
	while (qCur != NULL)
	{
		if (qCur->author.find(keyword) != std::string::npos)
		{
			if (cur->checkSubject(qCur->subject))
			{
				qCur->outputAnswer();
				qCur = qCur->next;
				soluong++;
			}
			else
				qCur = qCur->next;
		}
		else
			qCur = qCur->next;
	}
	if (soluong == 0)
		cout << "No question found." << endl;
	system("pause");
}

void questionList::deleteQuestion(User* cur)		//Delete the question in the list
{
	system("cls");
	gotoxy(0, 0);
	Question* temp = qHead;
	cout << "Enter question ID: ";
	int idSearch;
	cin >> idSearch;
	if (qHead == NULL)
	{
		cout << "No question found" << endl;
		return;
	}
	if (temp->ID == idSearch)
	{
		if (cur->checkSubject(temp->subject))
		{
			char press = _getch();
			if (press == 'Y' || press == 'y')
			{
				qHead = qHead->next;
				cout << "Deleted" << endl;
				delete[]temp->optArr;
				delete temp;
				return;
			}
			else
			{
				cout << "You did not delete that question!" << endl;
			}
		}
		else
		{
			if (qHead == NULL)
			{
				cout << "No question match" << endl;
				return;
			}
		}
	}
	while (temp->next != NULL)
	{
		if (temp->next->ID == idSearch)
		{
			if (cur->checkSubject(temp->next->subject))
			{
				Question *xoa = temp->next;
				temp->next = xoa->next;
				delete[]xoa->optArr;
				delete xoa;
				cout << "Deleted!" << endl;
				return;
			}
			else
			{
				cout << "No question match" << endl;
				return;
			}
		}
		temp = temp->next;
	}
	cout << "No question match" << endl;
}

void questionList::saveList()			//Save question to question list "inputQuestion.txt"
{
	Question* cur = qHead;
	int count = 1;
	out.open("inputQuestion");
	while (cur != NULL)
	{
		cur->ID = count++;
		cur->saveQuestion();
		cur = cur->next;
		if (cur != NULL)
			out << endl;
	}
	out.close();
	return;
}

void Question::saveQuestion()		//Save new question
{
	out << ID << endl << subject << endl << author << endl
		<< questionIs << endl << optionNum << endl;
	for (int i = 0; i < optionNum; ++i)
		out << optArr[i].option << endl;
	out << answers << endl << viewAble << endl << multiAns;
}

void questionList::remove()			//Remove the question
{
	Question* tmp = qHead;
	if (tmp != NULL)
		while (qHead != NULL)
		{
			qHead = qHead->next;
			delete[]tmp->optArr;
			delete tmp;
			tmp = qHead;
		}
}

void questionList::alterQuestion(User* cur)		//Alter the question in question list
{
	system("cls");
	gotoxy(0, 0);
	Question* temp = qHead;
	cout << "Enter question ID: ";
	int idSearch;
	cin >> idSearch;
	if (qHead == NULL)
	{
		cout << "No question found" << endl;
		return;
	}
	if (temp->ID == idSearch)
	{
		if (cur->checkSubject(temp->subject))
		{
			temp->alterQuestion();
			return;
		}
		else
		{
			if (qHead->next == NULL)
			{
				cout << "No question match" << endl;
				return;
			}
		}
	}
	while (temp->next != NULL)
	{
		if (temp->next->ID == idSearch)
		{
			if (cur->checkSubject(temp->next->subject))
			{
				//temp = temp->next;
				temp->next->alterQuestion();
				return;
			}
			else
			{
				cout << "No question match" << endl;
				return;
			}
		}
		temp = temp->next;
	}
	cout << "No question match" << endl;
}
	
void Question::alterQuestion()			//Alter the question
{
	cin.ignore(10, '\n');
	cout << "Question: ";
	getline(cin, questionIs);
	cout << "Number of answer options: ";
	cin >> optionNum;
	cin.ignore(10, '\n');
	delete[]optArr;
	optArr = new Option[optionNum];
	for (int i = 0; i < optionNum; ++i)
	{
		cout << "Option number " << i + 1 << ": ";
		cin.get(optArr[i].option, 45, '\n');
		cin.ignore(10, '\n');
	}
	for (int i = 0; i < optionNum; ++i)
	{
		char a = 'A' + i;
		char temp[50];
		temp[0] = a;
		temp[1] = '.';
		temp[2] = ' ';
		temp[3] = '\0';
		strcat(temp, optArr[i].option);
		strcpy(optArr[i].option, temp);
	}
	cout << "Answer (input letters representing correct answer(s) only): ";
	getline(cin, answers);
	answers = "Answer: " + answers;
	cout << "Viewability (0: not viewalbe, 1: viewable): ";
	cin >> viewAble;
	cout << "MultiAnswer (0: not viewalbe, 1: viewable): ";
	cin >> multiAns;
	return;
}

void questionList::addQuestion(User* cur)		//Add new question to question list
{
	system("cls");
	int count = 1;
	Question* countQ = qHead;
	while (countQ != NULL)
	{
		countQ = countQ->next;
		count++;
	}
	//Take info into temp variables
	//check SUBJECT
	//if SUBJECT matches one of teacher's subject, grant permission to create
	//else quit without new Question()
	cout << "If you see a blank screen, press enter" << endl;
	cin.ignore(10, '\n');
	system("cls");
	char tempSubject[10];
	cout << "Subject: ";
	cin.get(tempSubject, 10, '\n');
	cin.ignore(10, '\n');
	if (!cur->checkSubject(tempSubject))
	{
		cout << "You're not teaching that subject duh!" << endl;
		return;
	}
	Question* tmp = qHead;
	qHead = new Question();
	qHead->next = tmp;
	qHead->ID = count;
	qHead->addQuestion(tempSubject);
}

void Question::addQuestion(char sub[])		//Add new question
{
	cout << "Your name again: ";
	getline(cin, author);
	strcpy(subject, sub);
	cout << "Question: ";
	getline(cin, questionIs);
	cout << "Number of answer options: ";
	cin >> optionNum;
	cin.ignore(10, '\n');
	optArr = new Option[optionNum];
	for (int i = 0; i < optionNum; ++i)
	{
		cout << "Option number " << i + 1 << ": ";
		cin.get(optArr[i].option, 45, '\n');
		cin.ignore(10, '\n');
	}
	for (int i = 0; i < optionNum; ++i)
	{
		char a = 'A' + i;
		char temp[50];
		temp[0] = a;
		temp[1] = '.';
		temp[2] = ' ';
		temp[3] = '\0';
		strcat(temp, optArr[i].option);
		strcpy(optArr[i].option, temp);
	}
	cout << "Answer (input letters representing correct answer(s) only): ";
	getline(cin, answers);
	answers = "Answer: " + answers;
	cout << "Viewability (0: not viewalbe, 1: viewable): ";
	cin >> viewAble;
	cout << "MultiAnswer (0: not viewalbe, 1: viewable): ";
	cin >> multiAns;
	return;
}

bool Question::checkViewable()		//Check if question is viewable or not
{
	return viewAble;
}

void questionList::viewQuestion()		//Question menu
{
	Question* qCur = qHead;
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Show all";
	gotoxy(28, 5);
	cout << "2. Search keyword";
	gotoxy(28, 6);
	cout << "3. Search author";
	gotoxy(28, 7);
	cout << "4. Search subject";
	gotoxy(28, 8);
	cout << "5. Nope, just having some fun wandering";
	char decision;
	switch (keyControl(5))
	{
	case 1:
		system("cls");
		cout << "Do you want to see the answer (Y/N)?" << endl;
		decision = _getch();
		if (decision == 'Y' || decision == 'y')
		{
			while (qCur != NULL)
			{
				if (qCur->checkViewable())
					qCur->outputAnswer();
				qCur = qCur->next;
			}
			system("pause");
			return;
		}
		if (decision != 'N' && decision != 'n')
		{
			cout << "Invalid input, returning to option screen" << endl;
			system("pause");
			return;
		}
		else
		{
			while (qCur != NULL)
			{
				if (qCur->checkViewable())
					qCur->outputQuestion();
				qCur = qCur->next;
			}
			system("pause");
			return;
		}
	case 2:
		searchKeyword();
		break;
	case 3:
		searchAuthor();
		return;
	case 4:
		searchSubject();
		return;
	case 5:
		return;
	default:
		cout << "Invalid, going back" << endl;
		system("pause");
		return;
	}
}

void questionList::searchKeyword()		//Search question by keyword
{
	char decision;
	Question* qCur = qHead;
	system("cls");
	gotoxy(0, 0);
	int soluong = 0;
	cout << "Input the keyword: ";
	string keyword;
	getline(cin, keyword);
	if (qHead == NULL)
	{
		cout << "No question available";
		return;
	}
	cout << "Do you want to see the answer (Y/N)?" << endl;
	decision = _getch();
	if (decision == 'Y' || decision == 'y')
	{
		while (qCur != NULL)
		{
			if (qCur->questionIs.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputAnswer();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (decision != 'N' && decision != 'n')
	{
		cout << "Invalid input, returning to option screen" << endl;
		return;
	}
	else
	{
		while (qCur != NULL)
		{
			if (qCur->questionIs.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputQuestion();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (soluong == 0)
		cout << "No question match." << endl;
	system("pause");
	return;
}

void questionList::searchAuthor()		//Search author 
{
	char decision;
	Question* qCur = qHead;
	system("cls");
	gotoxy(0, 0);
	int soluong = 0;
	cout << "Input the author: ";
	string keyword;
	getline(cin, keyword);
	if (qHead == NULL)
	{
		cout << "No question available";
		system("pause");
		return;
	}
	cout << "Do you want to see the answer (Y/N)?" << endl;
	decision = _getch();
	if (decision == 'Y' || decision == 'y')
	{
		while (qCur != NULL)
		{
			if (qCur->author.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputAnswer();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (decision != 'N' && decision != 'n')
	{
		cout << "Invalid input, returning to option screen" << endl;
		system("pause");
		return;
	}
	else
	{
		while (qCur != NULL)
		{
			if (qCur->author.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputQuestion();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (soluong == 0)
		cout << "No question match." << endl;
	system("pause");
}

void questionList::searchSubject()		//Search subject 
{
	char decision;
	Question* qCur = qHead;
	system("cls");
	gotoxy(0, 0);
	int soluong = 0;
	cout << "Input the subject: ";
	string keyword;
	getline(cin, keyword);
	if (qHead == NULL)
	{
		cout << "No question available";
		system("pause");
		return;
	}
	cout << "Do you want to see the answer (Y/N)?" << endl;
	decision = _getch();
	if (decision == 'Y' || decision == 'y')
	{
		while (qCur != NULL)
		{
			string subjectTemp(qCur->subject);
			if (subjectTemp.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputAnswer();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (decision != 'N' && decision != 'n')
	{
		cout << "Invalid input, returning to option screen" << endl;
		system("pause");
		return;
	}
	else
	{
		while (qCur != NULL)
		{
			string subjectTemp(qCur->subject);
			if (subjectTemp.find(keyword) != std::string::npos)
			{
				if (qCur->checkViewable())
				{
					qCur->outputQuestion();
					qCur = qCur->next;
					soluong++;
				}
				else
					qCur = qCur->next;
			}
			else
				qCur = qCur->next;
		}
		system("pause");
		return;
	}
	if (soluong == 0)
		cout << "No question match." << endl;
	system("pause");
}

Question* questionList::getPointer()
{
	return qHead;
}