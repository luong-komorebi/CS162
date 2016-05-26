#pragma once
struct Circle{
	double x;
	double y;
	double r;
};
void inputCircleFromscr( Circle &c ) ;
void outputCirlceFromscr(Circle c);
void inputFromFile( Circle &c);
void outputFile( Circle c);
void area( Circle c);
void perimeter( Circle c);

