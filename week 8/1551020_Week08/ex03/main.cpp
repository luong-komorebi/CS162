#include "function.h"
#include <iostream>
using namespace std;
int main() {
	int x;
	cout << " Please enter a number: ";
	cin >> x;
	cout << " binary: ";
	toBinary(x);
	cout << endl;
	cout << "Sum : " << sumOfDigits(x);
	system("pause");
	return 0;
}