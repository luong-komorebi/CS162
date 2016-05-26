#pragma once
struct point{
	double x;
	double y;
};
void inputPointFromscr(point &p);
void outputPointFromscr( point p);
void inputFromFile( point &p1, point &p2);
void outputFile( point p1, point p2);
void updateX( point &p);
void updateY( point &p);
void getX( point p);
void getY( point p);
void Euclidedistance( point p1, point p2);
bool checkFirstQuad( point p);
bool checkThirdQuad( point p);
void move( point p);
