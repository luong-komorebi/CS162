#include <iostream>
#include <math.h>
using namespace std;
#include "fraction.h"

int main(){
	cout << " hello and welcome to my program" ;
	Complex c1, c2;
	inputComplex ( c1);
	cout << endl;
	outputComplex( c1);
	cout << endl;
	inputComplex ( c2);
	cout << endl;
	outputComplex( c2);
	cout << endl;
	add2Complex( c1, c2);
	cout << endl;
	substract2Complex(  c1, c2);
	cout << " c1: ";
	absComplex(c1);
	cout << " c2: ";
	absComplex(c2);
	cout << endl;
	ssComplex(c1,c2);
	cout << endl;
	return 0;
}