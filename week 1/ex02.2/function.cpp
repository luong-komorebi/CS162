#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#include "function.h"

void inputCircleFromscr( Circle &c ) {
	cout <<" Input x : ";
	cin>> c.x;
	cout <<"  Input y : ";
	cin >> c.y;
	cout << " Input radius : " ;
	cin>> c.r;
}
void outputCirlceFromscr(Circle c){
	cout <<" This is the output : ";
	cout << " ( " << c.x << "  & " <<c.y << ")" << " radius : " <<c.r;
}
void inputFromFile( Circle &c){
	ifstream file;
	file.open ("input.txt");
	file >> c.x;
	file >> c.y;
	file >> c.r;
	file.close ();
}
void outputFile( Circle c){
	ofstream out;
	out.open("out.txt");
	out << " center : ( " << c.x << "&" <<c.y << ")" << " radius : " <<c.r;
	out.close();
}
void perimeter( Circle c){
	double p=0.0;
	p= ( c.r * 2 ) * 3.14;
	cout << " the perimeter is : " << p;
}
void area( Circle c){
	double a=0.0;
	a= ( c.r * c.r ) * 3.14;
	cout << " the area is : " << a;
}
