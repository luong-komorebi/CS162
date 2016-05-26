#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
#include "fraction.h"
void inputFractionFromscr( Fraction &f){
	cout <<" Input numerator : ";
	cin>> f.num;
	cout <<"  Input denumerator : ";
	cin >> f.denum;
}

void outputFractionFromscr( Fraction f){
	cout <<" This is the output: ";
	cout << f.num << " / " <<f.denum;

}
Fraction addTwoFraction( Fraction f1 , Fraction f2){
	Fraction r;
	r.num= f1.num*f2.denum+ f1.denum*f2.num;
	r.denum= f1.denum*f2.denum;
	return r;
}
Fraction devideTwoFraction( Fraction f1 , Fraction f2){
	Fraction q;
	q.num= f1.num*f2.denum;
	q.denum= f1.denum*f2.num;
	return q;
}
Fraction Simplify ( Fraction &f){
	int temp= f.num;
	if ( temp < f.denum )
		temp= f.denum;
	for ( int i=2; i<=temp; i++){
		if ( f.num%i ==0 && f.denum%i==0){
			f.num/=i;
			f.denum/=i;
			i--;
		}
	}
	return f;
}
void updateNumerator( Fraction &f){
	int ans;
	cout <<" Do you want to update numerator ( 0 for yes / 1 for no)? " << endl;
	cin >> ans;
	if ( ans ==1 )
		cout << " Thanks lol!";
	else if ( ans== 0){
		cout << " Input the new numerator : ";
		cin >> f.num;
	}
	else cout << " Please read the instruction again then restart the program!  ( 0 or 1 only remember? )";

}
void updateDenumerator( Fraction &f){
	int ans;
	cout <<" Do you want to update denominator ( 0 for yes / 1 for no)? " << endl;
	cin >> ans;
	if ( ans ==1 )
		cout << " Thanks lol!";
	else if ( ans== 0){
		cout << " Input the new numerator : ";
		cin >> f.denum;
	}
	else cout << " Please read the instruction again then restart the program!  ( 0 or 1 only remember? )";

}
void getNum( Fraction f){
	cout << "This is the numerator: "<< f.num;
}
void getDenum( Fraction f){
	cout << "This is the denominator: "<< f.denum;
}
void inputFromFile( Fraction &f1, Fraction &f2){
	ifstream file;
	file.open ("input.txt");
	file >> f1.num;
	file >> f1.denum;
	file >> f2.num;
	file >>f2.denum;
	file.close ();
}
void outputFile( Fraction f1, Fraction f2){
	ofstream out;
	out.open("out.txt");
	out << f1.num << " / " <<f1.denum << endl;
	out << f2.num << " / " <<f2.denum;
	out.close();
}
