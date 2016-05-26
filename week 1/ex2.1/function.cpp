#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#include "function.h"

void inputPointFromscr( point &p ) {
	cout <<" Input x : ";
	cin>> p.x;
	cout <<"  Input y : ";
	cin >> p.y;
}
void outputPointFromscr( point p){
	cout <<" This is the output: ";
	cout << p.x << "  & " <<p.y;
}
void inputFromFile( point &p1, point &p2){
	ifstream file;
	file.open ("input.txt");
	file >> p1.x;
	file >> p1.y;
	file >> p2.x;
	file >> p2.y;
	file.close ();
}
void outputFile( point p1, point p2){
	ofstream out;
	out.open("out.txt");
	out << p1.x << " & " <<p1.y<< endl;
	out << p2.x << " & " <<p2.y << endl;
	out.close();
}
void updateX( point &p){
	int ans;
	cout <<" Do you want to update x? ( 0 for yes / 1 for no)? " << endl;
	cin >> ans;
	if ( ans ==1 )
		cout << " Thanks lol!";
	else if ( ans== 0){
		cout << " Input the new x : ";
		cin >> p.x;
	}
	else cout << " Please read the instruction again then restart the program!  ( 0 or 1 only remember? )";

}
void updateY( point &p){
	int ans;
	cout <<" Do you want to update y ( 0 for yes / 1 for no)? " << endl;
	cin >> ans;
	if ( ans ==1 )
		cout << " Thanks lol!";
	else if ( ans== 0){
		cout << " Input the new y : ";
		cin >> p.y;
	}
	else cout << " Please read the instruction again then restart the program!  ( 0 or 1 only remember? )";

}
void getX( point p){
	cout << "This is the x: "<< p.x;
}
void getY( point p){
	cout << "This is the y: "<< p.y;
}
void Euclidedistance( point p1, point p2){
	double m1=0.0;
	m1 = sqrt( pow((p1.x - p2.x),2)+ pow( (p1.y-p2.y),2)) ;
	cout << " the Euclide distance is : " << m1;
}
bool checkFirstQuad( point p){
	if ( p.x > 0 && p.y >0 ) 
		return true;
	return false;
}
bool checkThirdQuad( point p){
	if ( p.x < 0 && p.y <0 ) 
		return true;
	return false;
}
void move( point p){
	int n;
	cout << " How do you want to move ( 1 : left , 2: right , 3: up , 4 : down)" ;
	cin >> n;
	switch (n)
	{
	case 1:
		p.x-=1;
		break;
	case 2:
		p.x+=1;
		break;
	case 3:
		p.y+=1;
		break;
	case 4:
		p.y-=1;
		break;
	}
	cout << " new point : " << p.x << "&" << p.y;

}