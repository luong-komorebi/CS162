#include "function.h"
#include <iostream>
using namespace std;
int main() {
	int a[30],count=0;
	input(a, count);
	cout << "Here 's your input : ";
	output(a);
	cout << endl;
	cout << " Output in reverse: ";
	outputinreversed(a);
	cout << endl;
	int  n = count,soluong = count, m=0;
	cout << " Sum positive : " << sumpositive(a, m) << endl;
	cout << "The number of distinct value: " <<countDistinct(a,n,soluong)-1<< endl;
	if (checkOdd(a, count)){
		cout << "array contains odd" << endl;
	}
	else cout << " Array contains no odd" << endl;
	cout << " Max : " << checkMax(a, n, soluong) << endl;
	sort(a, count);
	cout << "Sorted:";
	for (int i = 1; i <= count; i++) {
		cout << a[i] << " ";
	}
	system("pause");


}