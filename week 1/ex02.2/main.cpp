#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
#include "function.h"
int main(){
	Circle c;
	int ans;
	cout <<" Hello and welcome to my program \n";
	cout << " How would you like to input( 0 for scr, 1 for file) ? ";
	cin >> ans;
	if( ans ==0) {
		inputCircleFromscr(c );
	}
	else if ( ans ==1){
		inputFromFile( c);
	}
	outputCirlceFromscr( c);
	cout<< endl;
	area(  c);
	cout<< endl;
	perimeter( c);
	outputFile(c);
	cout<< endl;
}