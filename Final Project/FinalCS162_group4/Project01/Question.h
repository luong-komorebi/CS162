#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include "Interface.h"
using namespace std;

struct Option
{
	char option[50];
};

class Question
{
private:
	string options;
	string answers;
	bool multiAns;
	bool viewAble;
	int optionNum;
public:
	Option* optArr;
	int ID;
	string author;
	char subject[10];
	string questionIs;
	Question* next;
	Question();
	~Question();
	void outputQuestion();		//show question without answer
	void outputAnswer();		//show question with answer
	void saveQuestion();		//Save new question
	void alterQuestion();		//Alter the question in question list
	bool checkViewable();		//Check if question is viewable or not
	void addQuestion(char sub[]);	//Add new question
};

class questionList
{
private:
	Question* qHead;

public:
	questionList();
	~questionList();
	void outputList();
	void searchSubject();				//Search subject 
	void viewQuestion(User* cur);		//View question menu
	void searchKeyword(User* cur);		//Search question by keyword
	void searchAuthor(User* cur);		//Search author by keyword
	void deleteQuestion(User* cur);		//Delete the question in the list
	void saveList();					//Save question to question list "inputQuestion.txt"
	void remove();						//Remove the question
	void alterQuestion(User* cur);		//Alter the question
	void addQuestion(User* cur);		//Add new question to question list
	void viewQuestion();				//Question menu 
	void searchKeyword();				//Search question by keyword
	void searchAuthor();				//Search author by keyword
	Question* getPointer();
};
