#pragma once
#include "File.h"
extern class questionList;
/*

This is for user activity
Which includes:
classDeclaration;
getInfo: getPass, getType;
Universal: checkPass, changePass, showInfo;
Admin:
Student:

*/
struct Subject
{
	char subject[10];
};

class userList;
class User
{
public:
	User* next;
	User(userList head);
	User();
	~User();
	//Universal functions:
	void updateInfo();				//Let user update information
	int getType();					//Get the type of the user
	int getStatus();				//Get status of the user
	bool checkUser(char id[]);		//check the username of the user
	bool checkPass(char pass[]);	//check the password of user
	void displayInfo();				//Display info of the User
	void saveUser();				//Save the info of User
	bool changePass();				//Change User password
	int getLen();					//Get the lenght of the username
	//Admin functions: 
	bool searchKeyword(char kw[]);	//Searches question by keyword
	void createAcc(userList head);	//Admin creates new user
	bool resetPass(userList head);	//Admin resets the user password
	bool deleteAcc(userList head);	//Admin deletes the user
	bool banAcc(userList head);		//Admin bans the user
	//Teacher functions:
	bool checkSubject(char qSubject[]);		//Checks the subjects
	//Student functions: 
	void outXML();							//Output the user information to file .xml
	Subject* subArr;
	void processSubject(questionList qList);	//Manage the subjects
private:
	char userName[14];
	char passWord[14];
	char name[30];
	char doB[11];
	int accType; // 0 is admin, 1 is teacher, 2 is student
	char address[40];
	bool sex; //1 is male
	bool status; //1 is activated
	int subNum;
};

class userList
{
public:
	userList();
	~userList();
	bool checkID(char inID[]);		//Check User ID
	void saveList();		//Save info of user to file "inputUser.txt"
	void display();			//Display the information of user
	void outXML();			//Output the list of user information to file .xml
	void filterList();		//Filter the list of users
	User* getPointer();
	void remove();			//Remove User
	void sortList();		//Sort the User list
private:
	User* pHead;
};