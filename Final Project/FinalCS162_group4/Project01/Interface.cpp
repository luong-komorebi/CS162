#include "Interface.h"
#include "Question.h"
using namespace std;
/*

This is for user interface
Which includes:
universal: gotoxy();
createFrame: logIn, mainScreen, logOut;
getUsername/Password: inputChar, deleteChar, printUser, printPass;

*/
void resize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void gotoxy(int x, int y) //make console points to position x,y
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
} //this function is taken from the internet, no specific discription is included

bool inputChar(char a[], char p)
{
	int tmp = strlen(a);
	if (tmp == 13) //13 is maximum length
		return false; //insert fail
	else
	{
		a[tmp++] = p; //Add newly entered char
		a[tmp] = '\0'; //Set next char to terminating null
		return true; //Insert success
	}
}

bool deleteChar(char a[])
{
	int tmp = strlen(a);
	if (tmp == 0) //if there is nothing left, delete fail
		return false;
	else
		a[--tmp] = '\0'; //turn last char into terminating null
	return true;
}

void printUser(char a[], int x, int y) //This function is to print username inputed (no more than 13 char)
{
	gotoxy(x, y); // (x, y) = position
	cout << "              "; //erase old info here
	gotoxy(x, y); // (x, y) = position
	cout << a; //print new one at exact same spot
}

void printPass(char a[], int x, int y) //This function is to print encripted password (no more than 13 char)
{
	gotoxy(x, y); //(x, y) = position
	cout << "               "; //erase old info here
	gotoxy(x, y); //(x, y) = position
	for (int i = 0; i < strlen(a); ++i)
		cout << "x";
	//print n 'x', where n is password string's length
}

void getPass(char passString[], int x, int y) //read password inputed from user into a string
{
	char press;
	gotoxy(x, y); //(x, y) = position = (38, 6)
	passString[0] = '\0'; //construction
	press = _getch(); //read the key user click
	while (press != 13) //if the user press other key than ENTER
	{
		if (press != 8) //if user did not press DELETE (backspace)
		{
			if (inputChar(passString, press)) //insert that key to string
				printPass(passString, x, y); //if added succesfully, update info on screen
		}
		else
			if (deleteChar(passString)) //delete last key out of the string
				printPass(passString, x, y); //if deleted successfully, update info on screen
		press = _getch(); //take next key
	}
	return;
}

void getUser(char user[], int x, int y) //read username inputed from user into a string
{
	char press;
	gotoxy(x, y); //(x, y) = position = (38, 5)
	user[0] = '\0'; //construction
	press = _getch();
	while (press != 13) //if the user press other key than ENTER
	{
		if (press != 8) //if user did not press DELETE (backspace)
		{
			if (inputChar(user, press)) //insert that key to string
				printUser(user, x, y); //if added successfully, update info on screen
		}
		else
			if (deleteChar(user)) //delete last key out of the string
				printUser(user, x, y);  //if deleted succesfully, update info on screen
		press = _getch();
	}
	return;
}

void createFrame() //create log in screen
{
	system("cls");
	gotoxy(28, 5);
	cout << "USERNAME: ";
	gotoxy(28, 6);
	cout << "PASSWORD: ";
}

bool logIn(userList pH, User* &p)
{
	p = pH.getPointer();
	char id[14], pass[14];
	getUser(id, 38, 5); //get username from keyboard
	getPass(pass, 38, 6); // get password from keyboard
	encryptPass(pass);
	while (p != NULL)
	{
		if (p->checkUser(id)) //find if there is any username match
		{
			if (p->getStatus() == 1) //check if it is activated
			{
				if (p->checkPass(pass)) //then check password
					return true;
				else // if not correct let them sign in again
				{
					gotoxy(20, 7);
					cout << "Invalid username or wrong password";
					gotoxy(20, 8);
					system("pause");
					system("cls");
					createFrame();
					return false;
				}
			}
			else
			{
				gotoxy(24, 7);
				cout << "Your account is not activated";
				gotoxy(24, 8);
				system("pause");
				system("cls");
				createFrame();
				return false;
			}
		}
		p = p->next;
	}
	//if no username matches, sign in again

	gotoxy(20, 7);
	cout << "Invalid username or wrong password";
	Sleep(1500);
	system("cls");
	createFrame();
	return false;
}

bool chooseType(userList head, User* cur)
{
	int a;
	system("cls");
	a = cur->getType();
	if (a == 0)
		return printAdmin(head, cur); //All the options lie here
	else if (a == 1)
		return printTeacher(head, cur); //All the options lie here
	else
		return printStudent(head, cur); //All the options lie here
}

bool printAdmin(userList head, User* cur)
{
	char keyPress;
	createFrameAdmin();
	switch (keyControl(9))
	{
	case 1:
		head.filterList();
		return true;
	case 2:
		head.sortList();
		return true;
	case 3:
		cur->createAcc(head);
		head.saveList();
		return true;
	case 4:
		system("cls");
		gotoxy(28, 3);
		cout << "Press coresponding key";
		gotoxy(28, 4);
		cout << "1. Remove";
		gotoxy(28, 5);
		cout << "2. Ban";
		keyPress = _getch();
		switch (keyPress)
		{
		case '1':
			cur->deleteAcc(head);
			head.saveList();
			break;
		case '2':
			cur->banAcc(head);
			head.saveList();
			break;
		default:
			gotoxy(28, 6);
			cout << "Unknown command, going back";
			Sleep(1500);
		}
		return true;
	case 5: cur->resetPass(head);
		head.saveList();
		return true;
	case 6: cur->updateInfo();
		head.saveList();
		return true;
	case 7: while (!cur->changePass());
		head.saveList();
		return true;
	case 8: logOut(head, cur);
		return false;
	case 9: return false;
	default:  cout << "Invalid key." << endl
		<< "Returning to option screen";
		Sleep(1000);
		return false;
	}
}

int keyControl(int num)
{
#define KEY_UP 72
#define KEY_DOWN 80

	const char key = '>'; //define arrow key
	int y = 4, z = 4 + (num - 1); //4 is initial y
	gotoxy(27, y); // 27 is initial x
	cout << key;
	char press = _getch();
	while (press != 13)
	{
		if ((press >= '1') && (press <= '9'))
			return press - '0';
		if (press == KEY_UP)
		{
			z = y;
			y = y - 1;
			if (y < 4)
				y = 4 + (num - 1); //4 is initial y
		}
		else
			if (press == KEY_DOWN)
			{
				z = y;
				y = y + 1;
				if (y > 4 + (num - 1)) //4 is initial y
					y = 4;
			}
		gotoxy(27, z); // 27 is initial x
		cout << " ";
		gotoxy(27, y); // 27 is initial x
		cout << key;
		press = _getch();
	}
	return y - 3;
}
void createFrameAdmin()
{
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4); //find x,  y later
	cout << "1. Filter"; //include option to output to XML
	gotoxy(28, 5);
	cout << "2. Sort"; //include option to output to XML
	gotoxy(28, 6);
	cout << "3. Create new account";
	gotoxy(28, 7);
	cout << "4. Remove or ban an account";
	gotoxy(28, 8);
	cout << "5. Reset password";
	gotoxy(28, 9);
	cout << "6. Update information";
	gotoxy(28, 10);
	cout << "7. Change password";
	gotoxy(28, 11);
	cout << "8. Log out";
	gotoxy(28, 12);
	cout << "9. Exit";
}
void logOut(userList head, User* cur)
{
	createFrame();
	while (!logIn(head, cur));
	while (chooseType(head, cur));
}

void createFrameTeacher()
{
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Subject realted"; //include option to output to XML
	gotoxy(28, 5);
	cout << "2. View questions"; //include option to output to XML
	gotoxy(28, 6);
	cout << "3. Alter questions";
	gotoxy(28, 7);
	cout << "4. Delete questions";
	gotoxy(28, 8);
	cout << "5. Add questions";
	gotoxy(28, 9);
	cout << "6. Update information ";
	gotoxy(28, 10);
	cout << "7. Change password";
	gotoxy(28, 11);
	cout << "8. Log out";
	gotoxy(28, 12);
	cout << "9. Exit";
}
void createFrameStudent()
{
	system("cls");
	gotoxy(18, 3);
	cout << "User arrow up/down to control, or press the number";
	gotoxy(28, 4);
	cout << "1. Search questions";
	gotoxy(28, 5);
	cout << "2. Update information";
	gotoxy(28, 6);
	cout << "3. Change password";
	gotoxy(28, 7);
	cout << "4. Log out";
	gotoxy(28, 8);
	cout << "5. Exit";
}
bool printTeacher(userList head, User* cur)
{
	questionList qList;
	createFrameTeacher();
	switch (keyControl(8))
	{
	case 1:
		cur->processSubject(qList);
		return true;
	case 2:
		qList.viewQuestion(cur);
		qList.saveList();
		qList.remove();
		return true;
	case 3:
		qList.alterQuestion(cur);
		qList.saveList();
		qList.remove();
		Sleep(1000);
		return true;
	case 4:
		qList.deleteQuestion(cur);
		qList.saveList();
		qList.remove();
		Sleep(1000);
		return true;
	case 5:
		qList.addQuestion(cur);
		qList.saveList();
		qList.remove();
		Sleep(1000);
		return true;
	case 6:
		cur->updateInfo();
		return true;
	case 7:
		while (!cur->changePass());
		return true;
	case 8:
		qList.saveList();
		qList.remove();
		logOut(head, cur);
		return false;
	case 9:
		qList.saveList();
		qList.remove();
		return false;
	default:
		system("cls");
		cout << "Invalid key." << endl
			<< "Returning to option screen";
		Sleep(1000);
		return true;
	}
}
bool printStudent(userList head, User* cur)
{
	//Initialize question list here
	questionList qList;
	createFrameStudent();
	switch (keyControl(5))
	{
	case 1:
		qList.viewQuestion();
		return true;
	case 2: cur->updateInfo();
		return true;
	case 3: while (!cur->changePass());
		return true;
	case 4: logOut(head, cur);
		return false;
	case 5: return false;
	default: return false;
	}
}
void encryptPass(char a[])
{
	for (int i = 0; i < strlen(a); ++i)
		a[i] = (a[i] + 5) % 128;
	return;
}