#include <iostream>
#include <math.h>
using namespace std;
#include "fraction.h"
#include <fstream>

int main(){
	Fraction f1, f2, f3;
	int ans;
	cout << " hello , welcome to my program!";
	cout << "Do you want to input from screen ( 0)  or file (1) ? " ;
	cin>> ans;
	if( ans ==0) {
		inputFractionFromscr(f1);
		inputFractionFromscr(f2);
	}
	else if ( ans ==1){
		inputFromFile( f1,f2);
	}
	else cout << " read the instruction again!";


	Fraction k= addTwoFraction( f1, f2);
	cout<< " the sum of 2 fraction: " << k.num << " / " << k.denum << endl;
	Fraction k1=Simplify(f1);
	cout << " sum simplified : " << k1.num << " / " <<k1.denum << endl;
	Fraction l= devideTwoFraction( f1, f2);
	cout<< " the devision of 2 fraction: " << l.num << " / " << l.denum << endl;
	Fraction l1=Simplify(f1);
	cout << " devision simplified : " << l1.num << " / " <<l1.denum << endl;
	Fraction m1=Simplify(f1);
	cout << " f1 simplified : " << m1.num << " / " << m1.denum << endl;
	Fraction m2=Simplify(f2);
	cout << " f1 simplified : " << m2.num << " / " << m2.denum << endl;
	inputFractionFromscr(f3);
	cout<< endl;
	getNum(f3);
	cout<< endl;
	getDenum(f3);
	cout<< endl;
	updateNumerator(f3);
	cout<< endl;
	updateDenumerator(f3);
	cout<< endl;
	outputFractionFromscr( f1);
	cout<< endl;
	outputFractionFromscr( f2);
	cout<< endl;
	return 0;
	outputFile( f1, f2);
}