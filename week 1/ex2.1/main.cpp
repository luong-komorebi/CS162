#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
#include "function.h"
int main(){
	point p1,p2;
	int ans;
	cout <<" Hello and welcome to my program \n";
	cout << " How would you like to input( 0 for scr, 1 for file) ? ";
	cin >> ans;
	if( ans ==0) {
		inputPointFromscr(p1);
		inputPointFromscr(p2);
	}
	else if ( ans ==1){
		inputFromFile( p1,p2);
	}
	updateX( p1);
	cout<<endl;
	updateY( p1);
	getX( p1);
	cout<<endl;
	getY( p1);
	cout<<endl;
	updateX( p2);
	cout<<endl;
	updateY( p2);
	cout<<endl;
	getX( p2);
	cout<<endl;
	getY( p2);
	cout<<endl;
	Euclidedistance( p1,p2);
	cout<<endl;
	bool i1=checkFirstQuad( p1);
	if ( i1== true)
		cout << " The 1st point is belonged to the first quadrant ";
	else cout << " The 1st point is not belonged to the first quadrant ";
	cout<<endl;
	bool i2=checkThirdQuad( p1);
	if ( i2 == true)
		cout << " The 1st point is belonged to the first quadrant ";
	else cout << " The 1st point is not belonged to the first quadrant ";
	bool i3=checkFirstQuad( p2);
	cout<<endl;
	if ( i3 == true)
		cout << " The 2nd point is belonged to the first quadrant ";
	else cout << " The 2nd point is not belonged to the first quadrant ";
	cout<<endl;
	bool i4=checkThirdQuad( p2);
	if ( i4 == true)
		cout << " The 2nd point is belonged to the first quadrant ";
	else cout << " The 2nd point is not belonged to the first quadrant ";
	cout<<endl;
	move(p1);
	cout<<endl;
	move( p2);
	cout<<endl;
	outputPointFromscr( p1);
	cout<<endl;
	outputPointFromscr( p2);
	cout<<endl;
	outputFile( p1, p2);
	return 0;
}