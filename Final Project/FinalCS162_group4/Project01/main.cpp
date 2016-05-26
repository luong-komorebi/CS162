#include "Interface.h"

int main()
{
	userList head;
	User* cur;
	//initialize linked list
	createFrame(); //Create frame
	while (!logIn(head, cur));
	//If logIn fail, let user logIn again
	while (chooseType(head, cur)); //create option screen according to user type;
	system("cls");
	gotoxy(0, 0);
	cout << "Done." << endl;
	head.saveList();
	head.remove();
	return 0;
}