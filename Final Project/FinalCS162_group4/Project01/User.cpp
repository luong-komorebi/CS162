#include "Interface.h"

extern std::ifstream in;
extern std::ofstream out;

User::User()
{
	if (in.is_open())
	{
		in.getline(userName, 14);
		in.getline(passWord, 14);
		in.getline(name, 30);
		in.getline(doB, 11);
		in.getline(address, 40);
		in >> accType;
		if (accType == 1)
		{
			in >> subNum;
			in.ignore(10, '\n');
			subArr = new Subject[subNum];
			for (int i = 0; i < subNum; ++i)
			{
				in.getline(subArr[i].subject, 10, '\n');
			}
		}
		in >> sex;
		in >> status;
		in.get();
		next = NULL;
		//Sleep(1000);
	}
}
User::~User()
{
}
User::User(userList head)
{
	while (true)
	{
		system("cls");
		gotoxy(0, 0);
		cout << "CREATE NEW ACCOUT" << endl;
		cout << "Username: ";
		cin.get(userName, 14, '\n');
		cin.ignore(100, '\n');
		if (!head.checkID(userName))
			break;
		cout << "That username is not unique" << endl;
		system("pause");
	}
	cout << "Name: ";
	cin.get(name, 30, '\n');
	cin.ignore(100, '\n');
	cout << "Date of birth (yyyy-mm-dd): ";
	cin.get(doB, 11, '\n');
	cin.ignore(100, '\n');
	cout << "Address: ";
	cin.get(address, 40, '\n');
	cin.ignore(100, '\n');
	cout << "Sex (0: female, 1: male): ";
	cin >> sex;
	cout << "Type (0: admin, 1: teacher): ";
	cin >> accType;
	status = 1;
	for (int i = 0; i <= 9; ++i)
		passWord[i] = i + '0';
	passWord[10] = '\0';
	if (accType == 1)
	{
		cout << "Numbers of subject: ";
		cin >> subNum;
		subArr = new Subject[subNum];
		for (int i = 0; i < subNum; ++i)
		{
			cout << "Enter subject: ";
			cin.ignore(10, '\n');
			cin.get(subArr[i].subject, 10, '\n');
		}
	}
	cout << "You have successfully created a new account" << endl;
	cout << "Deafault password: " << passWord << endl;
	Sleep(500);
	cout << "Returning to option screen";
	Sleep(1500);
	cin.ignore(1, '\n');
	encryptPass(passWord);
}
bool User::checkUser(char id[])
{
	if (strcmp(id, userName) == 0)
		return true;
	return false;
}
bool User::checkPass(char pass[])
{
	if (strcmp(pass, passWord) == 0)
		return true;
	return false;
}
int User::getType()			//Get the type of the user
{
	return accType;
}
void User::displayInfo()	//Display info of the User
{
	cout << userName << endl << name << endl;
	if (accType == 0)
		cout << "Admin" << endl;
	else
		if (accType == 2)
			cout << "Student" << endl;
		else
		{
			cout << "Teacher" << endl;
			for (int i = 0; i < subNum; ++i)
				cout << subArr[i].subject << endl;
		}
	if (1 == status)
		cout << "Activated" << endl;
	else
		cout << "Deactivated" << endl;
	cout << "______________" << endl;
}
void User::saveUser()		//Save the info of User
{
	out << userName << endl << passWord << endl
		<< name << endl << doB << endl << address << endl
		<< accType << endl;
	if (accType == 1)
	{
		out << subNum << endl;
		for (int i = 0; i < subNum; ++i)
			out << subArr[i].subject << endl;
	}
	out << sex << endl << status;
}
bool User::changePass()		//Change User password
{
	char oldPass[14], newPass[14], newPass2[14];
	system("cls");
	gotoxy(12, 0);
	cout << "CHANGE PASSWORD (Y/N)?";
	char press = _getch();
	if (press != 'y' && press != 'Y')
		return true;
	gotoxy(0, 1);
	cout << "Enter old password: ";
	getPass(oldPass, 20, 1);
	gotoxy(0, 2);
	cout << "Enter new password: ";
	getPass(newPass, 20, 2);
	gotoxy(0, 3);
	cout << "Confirm password: ";
	getPass(newPass2, 18, 3);
	gotoxy(0, 4);
	cout << "Loading";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << "." << endl;
	Sleep(500);
	encryptPass(newPass);
	encryptPass(newPass2);
	if (strcmp(oldPass, passWord) == 0 && strcmp(newPass, newPass2) == 0)
	{
		cout << "Suceeded!" << endl;
		cout << "Returning to option screen" << endl;
		system("pause");
		strcpy(passWord, newPass);
		return true;
	}
	else
	{
		cout << "Change password failed" << endl;
		cout << "We will let you try again!" << endl;
		system("pause");
		return false;
	}
}
int User::getStatus()		//Get status of the user
{
	return status;
}
userList::userList()
{
	User* cur;
	in.open("inputUser.txt");
	if (in.is_open())
	{
		if (!in.eof())
		{
			pHead = new User();
			cur = pHead;
		}
		while (!in.eof())
		{
			cur->next = new User();
			cur = cur->next;
		}
		in.close();
	}
	else
		cout << "ya";
}
userList::~userList()
{
}
User* userList::getPointer()
{
	return pHead;
}
void userList::display()		//Display the information of user
{
	User* cur = pHead;
	while (cur != NULL)
	{
		cur->displayInfo();
		cur = cur->next;
	}
}
void userList::remove()		//Remove User
{
	User* tmp = pHead;
	if (tmp != NULL)
		while (pHead != NULL)
		{
			pHead = pHead->next;
			if (tmp->getType() == 1)
				delete[]tmp->subArr;
			delete tmp;
			tmp = pHead;
		}
}
void User::updateInfo() //Let user update information
{
	system("cls");
	char choice;
	gotoxy(0, 0);
	cout << "What do you want to update?" << endl;
	cout << "1. Name" << endl;
	cout << "2. Date of birth: " << endl;
	cout << "3. Nope, i don't want to update anything" << endl;
	choice = _getch();
	switch (choice)
	{
	case '1': system("cls");
		gotoxy(0, 0);
		cout << "Sorry we get your name wrong" << endl;
		cout << "Old name: " << name << endl;
		cout << "Enter your name: ";
		cin.get(name, 30, '\n');
		cin.ignore(100, '\n');
		cout << "Loading";
		Sleep(100);
		cout << ".";
		Sleep(100);
		cout << ".";
		Sleep(100);
		cout << "." << endl;
		Sleep(500);
		cout << "Suceeded!" << endl;
		cout << "Returning to option screen" << endl;
		Sleep(1000);
		break;
	case '2':
		system("cls");
		cout << "Re-enter your birthday" << endl;
		char date[3], month[3], year[5];
		cout << "Enter date: ";
		cin.get(date, 3, '\n');
		cin.ignore(10, '\n');
		cout << "Enter month: ";
		cin.get(month, 3, '\n');
		cin.ignore(10, '\n');
		cout << "Enter year: ";
		cin.get(year, 5, '\n');
		cin.ignore(10, '\n');
		if (1 == strlen(date))
		{
			date[1] = date[0];
			date[2] = '\0';
			date[0] = '0';
		}
		if (1 == strlen(month))
		{
			month[1] = month[0];
			month[2] = '\0';
			month[0] = '0';
		}
		//Create new string, combine 3 string of date, month, year
		//to make completed date of birth (yyyy-mm-dd)
		char newDOB[11];
		newDOB[0] = year[0];
		newDOB[1] = year[1];
		newDOB[2] = year[2];
		newDOB[3] = year[3];
		newDOB[4] = '-';
		newDOB[5] = month[0];
		newDOB[6] = month[1];
		newDOB[7] = '-';
		newDOB[8] = date[0];
		newDOB[9] = date[1];
		newDOB[10] = '\0';
		for (int i = 0; i < 11; ++i)
			doB[i] = newDOB[i];
		cout << "Loading";
		Sleep(100);
		cout << ".";
		Sleep(100);
		cout << ".";
		Sleep(100);
		cout << "." << endl;
		Sleep(500);
		cout << "Suceeded!" << endl;
		cout << "Returning to option screen" << endl;
		Sleep(1000);
		break;
	case '3':
		return;
	default:
		cout << "Wrong input, it now returns to option screen" << endl;
		Sleep(1000);
		return;
	}
	return;
}
void userList::saveList()		//Save info of user to file "inputUser.txt"
{
	User* cur = pHead;
	out.open("inputUser.txt");
	while (cur != NULL)
	{
		cur->saveUser();
		cur = cur->next;
		if (cur != NULL)
			out << endl;
	}
	out.close();
	return;
}
bool User::deleteAcc(userList head)		//Admin deletes the user
{
	char id[14];
	User* tmp = head.getPointer();
	system("cls");
	gotoxy(0, 0);
	cout << "Enter username of account you want to remove: ";
	cin.get(id, 14, '\n');
	cin.ignore(100, '\n');
	if (strcmp(id, userName) == 0)
	{
		cout << "You cannot remove your own account" << endl;
		Sleep(1000);
		return false;
	}
	while (tmp != NULL)
	{
		if (tmp->checkUser(id))
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		cout << "That account was not found!" << endl;
		cout << "Returning to option screen";
		Sleep(1000);
		return false;
	}
	cout << "Are you sure you want to remove this account (Y/N)?";
	char press = _getch();
	cout << endl;
	cout << "Loading";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << "." << endl;
	Sleep(500);
	if (press == 'Y' || press == 'y')
	{
		User* tmp2 = head.getPointer();
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = tmp->next;
		delete tmp;
		cout << "Suceeded!" << endl;
		cout << "Returning to option screen" << endl;
		Sleep(1000);
		return true;
	}
	cout << "You did not remove that account" << endl;
	cout << "Returning to option screen" << endl;
	Sleep(1000);
	return false;
}
void User::createAcc(userList head)		//Admin creates new user
{
	User* temp = next;
	next = new User(head);
	next->next = temp;
}
bool User::resetPass(userList head)		//Admin resets the user password
{
	char id[14];
	User* tmp = head.getPointer();
	system("cls");
	gotoxy(0, 0);
	cout << "Enter username of account you want to reset passsword: ";
	cin.get(id, 14, '\n');
	cin.ignore(100, '\n');
	if (strcmp(id, userName) == 0)
	{
		cout << "You cannot reset your own password" << endl;
		Sleep(1000);
		return false;
	}
	while (tmp != NULL)
	{
		if (tmp->checkUser(id))
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		cout << "That account was not found!" << endl;
		cout << "Returning to option screen";
		Sleep(1000);
		return false;
	}
	for (int i = 0; i <= 9; ++i)
		tmp->passWord[i] = i + '0';
	tmp->passWord[10] = '\0';
	encryptPass(passWord);
	cout << "Loading";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << "." << endl;
	Sleep(500);
	cout << "Suceeded!" << endl;
	cout << "Returning to option screen" << endl;
	system("pause");
	return true;
}	
void userList::filterList()		//Filter the list of users
{
	int a;
	char keyword[14];
	User* tmp = pHead;
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Show all";
	gotoxy(28, 5);
	cout << "2. Type filter";
	gotoxy(28, 6);
	cout << "3. Status filter";
	gotoxy(28, 7);
	cout << "4. Username filter";
	gotoxy(28, 8);
	cout << "5. Nope, misclicked!";
	switch (keyControl(5))
	{
	case 1:
		system("cls");
		display();
		outXML();
		cout << "XML file for the whole list of users is created" << endl;
		system("pause");
		return;
	case 2:
		system("cls");
		gotoxy(18, 3);
		cout << "User arrow up/down to control, or press the number";
		gotoxy(28, 4); //find x,  y later
		cout << "1. Admin";
		gotoxy(28, 5);
		cout << "2. Teacher";
		gotoxy(28, 6);
		cout << "3. Student";
		a = keyControl(3);
		system("cls");
		while (tmp != NULL)
		{
			if (tmp->getType() == a - 1)
				tmp->displayInfo();
			tmp = tmp->next;
		}
		system("pause");
		return;
	case 3:
		system("cls");
		while (tmp != NULL)
		{
			if (tmp->getStatus() == 1)
				tmp->displayInfo();
			tmp = tmp->next;
		}
		system("pause");
		return;
	case 4: system("cls");
		cout << "Enter search keyword: ";
		cin.get(keyword, 14, '\n');
		cin.ignore(100, '\n');
		while (tmp != NULL)
		{
			if (tmp->searchKeyword(keyword))
				tmp->displayInfo();
			tmp = tmp->next;
		}
		system("pause");
		return;
	case 5: return;
	default: gotoxy(28, 9);
		cout << "Invalid key" << endl;
		Sleep(1000);
		return;
	}
}

bool User::searchKeyword(char kw[])		//searches question by keyword
{
	int count;
	int len = strlen(kw);
	for (int i = 0; i <= getLen() - len; ++i)
	{
		count = 0;
		for (int j = 0; j < len; ++j)
			if (kw[j] == userName[i + j])
				count++;
		if (count == len)
			return true;
	}
	return false;
}

int User::getLen()			//Get the lenght of the username
{
	return strlen(userName);
}

void userList::sortList()		//Sort the User list
{
	User* tmp = pHead;
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Show all";
	gotoxy(28, 5);
	cout << "2. Type sort";
	gotoxy(28, 6);
	cout << "3. Username sort";
	gotoxy(28, 7);
	cout << "4. Nope, just wanna take a tour";
	switch (keyControl(4))
	{
	case 1:
		system("cls");
		display();
		system("pause");
		return;
	case 2:
		system("cls");
		while (tmp != NULL)
		{
			if (tmp->getType() == 0)
				tmp->displayInfo();
			tmp = tmp->next;
		}
		tmp = pHead;
		while (tmp != NULL)
		{
			if (tmp->getType() == 1)
				tmp->displayInfo();
			tmp = tmp->next;
		}
		tmp = pHead;
		while (tmp != NULL)
		{
			if (tmp->getType() == 2)
				tmp->displayInfo();
			tmp = tmp->next;
		}
		system("pause");
		return;
	case 3:

	case 4:
		return;
	default:
		gotoxy(28, 9);
		cout << "Invalid key" << endl;
		Sleep(1000);
		return;
	}
}

bool User::checkSubject(char qSubject[])		//Checks the subjects
{
	for (int i = 0; i < subNum; ++i)
		if (strcmp(subArr[i].subject, qSubject) == 0)
			return true;
	return false;
}

bool userList::checkID(char inID[])		//Check User ID
{
	User* tmp = pHead;
	while (tmp != NULL)
	{
		if (tmp->checkUser(inID))
			return true;
		tmp = tmp->next;
	}
	return false;
}

void userList::outXML()			//Output the list of user information to file .xml
{
	User* cur = pHead;
	out.open("userList.xml");
	if (out)
	{
		out << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>";
		out << "<userList>" << endl << endl;
		while (cur != NULL)
		{
			cur->outXML();
			cur = cur->next;
		}
		out << "</userList>";
		out.close();
	}
}

void User::outXML()			//Output the user information to file .xml
{
	out << "<Username>" << userName << "</Username>" << endl;
	out << "<Name>" << name << "</Name>" << endl;
	out << "<DateOfBirth>" << doB << "</DateOfBirth>" << endl;
	if (accType == 0)
		out << "<AccType>Admin</Acctype>" << endl;
	else if (accType == 1)
		out << "<AccType>Teacher</Acctype>" << endl;
	else
		out << "<AccType>Student</Acctype>" << endl;
	out << "<Address>" << address << "</Address>" << endl;
	if (sex == 1)
		out << "<Sex>Male</Sex>" << endl;
	else
		out << "<Sex>Female</Sex>" << endl;
	if (status == 1)
		out << "<Status>Activated</Status>" << endl;
	else
		out << "<Status>Activated</Status>" << endl;
	out << endl;
}

bool User::banAcc(userList head)		//Admin bans the user
{	
	char id[14];
	User* tmp = head.getPointer();
	system("cls");
	gotoxy(0, 0);
	cout << "Enter username of account you want to ban: ";
	cin.get(id, 14, '\n');
	cin.ignore(100, '\n');
	if (strcmp(id, userName) == 0)
	{
		cout << "You cannot ban your own account" << endl;
		Sleep(1000);
		return false;
	}
	while (tmp != NULL)
	{
		if (tmp->checkUser(id))
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		cout << "That account was not found!" << endl;
		cout << "Returning to option screen";
		Sleep(1000);
		return false;
	}
	cout << "Are you sure you want to ban this account (Y/N)?";
	char press = _getch();
	cout << endl;
	cout << "Loading";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << ".";
	Sleep(100);
	cout << "." << endl;
	Sleep(500);
	if (press == 'Y' || press == 'y')
	{
		tmp->status = 0;
		cout << "Suceeded!" << endl;
		cout << "Returning to option screen" << endl;
		Sleep(1000);
		return true;
	}
	cout << "You did not ban that account" << endl;
	cout << "Returning to option screen" << endl;
	Sleep(1000);
	return false;
}

void User::processSubject(questionList qList)		//Manage the subjects
{
	int tempCount;
	char temp[10];
	Subject* tmp;
	Question* qCur;
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Add subject"; //include option to output to XML
	gotoxy(28, 5);
	cout << "2. View my subjects"; //include option to output to XML
	gotoxy(28, 6);
	cout << "3. View questions of one subject";
	gotoxy(28, 7);
	cout << "4. Delete subject";
	gotoxy(28, 8);
	cout << "5. Edit subject";
	gotoxy(28, 9);
	cout << "6. Going back out";
	switch (keyControl(6))
	{
	case 1:
		system("cls");
		cout << "Enter the subject: ";
		cin.getline(temp, 10);
		for (int i = 0; i < subNum; ++i)
			if (strcmp(subArr[i].subject, temp) == 0)
			{
				cout << "You're already teaching that subject" << endl;
				system("pause");
				return;
			}
		subNum++;
		tmp = new Subject[subNum];
		for (int i = 0; i < subNum - 1; ++i)
			strcpy(tmp[i].subject, subArr[i].subject);
		strcpy(tmp[subNum - 1].subject, temp);
		delete[]subArr;
		subArr = tmp;
		cout << "Done" << endl;
		system("pause");
		return;
	case 2:
		system("cls");
		cout << "You are currently responsible for: " << endl;
		for (int i = 0; i < subNum; ++i)
			cout << "  -" << subArr[i].subject << endl;
		system("pause");
		return;
	case 3:
		system("cls");
		cout << "Enter the subject: ";
		cin.getline(temp, 10);
		for (int i = 0; i < subNum; ++i)
			if (strcmp(subArr[i].subject, temp) == 0)
			{
				cout << "Question list: " << endl;
				qCur = qList.getPointer();
				while (qCur != NULL)
				{
					if (strcmp(qCur->subject, temp) == 0)
						qCur->outputQuestion();
					qCur = qCur->next;
				}
				system("pause");
				return;
			}
		cout << "You are not teaching that subject, going back" << endl;
		system("pause");
		return;
	case 4:
		system("cls");
		cout << "Enter the subject: ";
		cin.getline(temp, 10);
		for (int i = 0; i < subNum; ++i)
			if (strcmp(subArr[i].subject, temp) == 0)
			{
				subNum--;
				tmp = new Subject[subNum];
				for (int j = 0; j < subNum; ++j)
					if (j == i)
						j--;
					else
						strcpy(tmp[j].subject, subArr[j].subject);
				delete[]subArr;
				subArr = tmp;
				return;
			}
		cout << "You're already teaching that subject" << endl;
		system("pause");
		return;
	case 5:
		system("cls");
		cout << "Enter subject you want to change: ";
		cin.getline(temp, 10);
		for (int i = 0; i < subNum; ++i)
			if (strcmp(subArr[i].subject, temp) == 0)
			{
				cout << "Enter subject you want to change to: ";
				cin.getline(subArr[i].subject, 10);
				cout << "Done" << endl;
				system("pause");
				return;
			}
		cout << "You are not teaching that subject" << endl;
		system("pause");
		return;
	case 6:
		return;
	default:
		cout << "Invalid command, going back" << endl;
		system("pause");
		return;
	}
}