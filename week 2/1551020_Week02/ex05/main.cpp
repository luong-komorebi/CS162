#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include "function.h"

int main(){
	int n;
	int *a;
	int insert;
	InputFromFile ( n ,  a);
	int k= LargestNumber(n,a);
	cout <<" The largest number : " << k <<endl;
	cout << " Sorting : " ;
	SortOddEven( n, a);
	cout <<" What do you want to insert ?" ;
	cin >> insert;
	
	Insert ( n,a,insert);
	delete[] a;
	return 0;
}
