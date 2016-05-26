#pragma once
struct Fraction{
	int num;
	int denum;
};
void inputFractionFromscr( Fraction &f);
void outputFractionFromscr( Fraction f);
Fraction addTwoFraction( Fraction f1 , Fraction f2);
Fraction devideTwoFraction( Fraction f1 , Fraction f2);
Fraction Simplify ( Fraction &f);
void updateNumerator( Fraction &f);
void updateDenumerator( Fraction &f);
void getNum( Fraction f);
void getDenum( Fraction f);
void inputFromFile( Fraction &f1, Fraction &f2);
void outputFile( Fraction f1, Fraction f2);

