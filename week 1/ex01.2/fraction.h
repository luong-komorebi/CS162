#pragma once
struct Complex{
	double real;
	double unreal;
};
void inputComplex ( Complex &c);
void outputComplex( Complex c);
void add2Complex( Complex c1, Complex c2);
void substract2Complex( Complex c1, Complex c2);
void absComplex( Complex c);
void ssComplex( Complex c1, Complex c2);