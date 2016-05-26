#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#include "function.h"

void inputStdFromscr( student &S) {
	cout <<" Input ID : ";
	cin.get();
	cin.getline( S.ID , 8, '\n');
	cout <<" Input Name : ";
	cin.getline(S.name, 31, '\n');
	cout <<" Input Address : ";
	cin.getline( S.address, 51, '\n');
	cout <<" Input Dob : ";
	cin.getline( S.dob , 31, '\n');
	cout <<" Input Grade ";
	cin >> S.grade;
}
void outputStdFromscr(student S){
	cout <<" This is the student info : ";
	cout << " ID : " << S.ID <<endl;
	cout << " Name : " << S.name << endl;
	cout << " Address : " << S.address<< endl;
	cout << " DOB :  " << S.dob << endl;
	cout << " Grade: " << S.grade << endl;
}
void classifyS( student S) {
	if ( S.grade ==10 )
		cout << " Remark: Excellent Student ";
	else if ( S.grade <10  && S.grade>9 )
		cout << " Remark: Good Student ";
	else if ( S.grade <9 && S.grade > 6.5 )
		cout << " Remark: Average Student ";
	else if ( S.grade <6.5 && S.grade >1 )
		cout << " Remark: Bad Student ";
	else
		cout << " Remark: This student should be banned from school";
	cout << endl;
}
void inputFromFile( student &S){
	ifstream fin;
	fin.open ("input.txt");
	fin.getline( S.ID , 8, '\n');
	fin.getline(S.name, 31, '\n');
	fin.getline( S.address, 51, '\n');
	fin.getline( S.dob , 31, '\n');
	fin >> S.grade;
	fin.close();
}
void outputFile( student S){
	ofstream out;
	out.open("out.txt");
	out <<" This is the student info : ";
	out << " ID : " << S.ID <<endl;
	out << " Name : " << S.name << endl;
	out << " Address : " << S.address<< endl;
	out << " DOB :  " << S.dob << endl;
	out << " Grade: " << S.grade << endl;
	out.close();
}

