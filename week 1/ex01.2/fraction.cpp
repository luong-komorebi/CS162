#include <iostream>
#include <math.h>
using namespace std;
#include "fraction.h"

void inputComplex ( Complex &c){
	cout << " Input the real : " ;
	cin >> c.real;
	cout << " input the imaginary: " ;
	cin >> c.unreal;
}
void outputComplex( Complex c){
	cout << c.real << " + "<<c.unreal <<"i";
}
void add2Complex( Complex c1, Complex c2){
	Complex c3;
	c3.real= c1.real+ c2.real;
	c3.unreal = c1.unreal+ c2.unreal;
	outputComplex(c3);
}
void substract2Complex( Complex c1, Complex c2){
	Complex c3;
	c3.real= c1.real- c2.real;
	c3.unreal = c1.unreal- c2.unreal;
	outputComplex( c3);
}
void absComplex( Complex c){
	float m1=0.0;
	m1 = sqrt( c.real*c.real + c.unreal*c.unreal);
	cout << " the absolute value of complex number : " << m1;
}
void ssComplex( Complex c1, Complex c2){
	if ( ( c1.real == c2.real ) && ( c1.unreal == c2.unreal))
		cout <<" These complex numbers are equal " ;
	else cout << " These complex numbers are not equal" ;
}