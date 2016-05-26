#pragma once
struct student{
	char ID[8];
	char name[31];
	char address[51];
	char dob[31];
	int grade;
};
void inputStdFromscr( student &S);
void outputStdFromscr(student S);
void classifyS( student S);
void inputFromFile( student &S);
void outputFile( student S);
