#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
#include "function.h"
int main(){
	student S;
	int ans;
	cout <<" Hello and welcome to my program \n";
	cout << " How would you like to input( 0 for scr, 1 for file) ? ";
	cin >> ans;
	if( ans ==0) {
		inputStdFromscr( S);
	}
	else if ( ans ==1){
		inputFromFile(S);
	}
	outputStdFromscr( S);
	cout<< endl;
	classifyS( S);
	cout<< endl;
	outputFile(S);
	cout<< endl;
}