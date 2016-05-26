#include <iostream>
#include "function.h"
using namespace std;

int main() {
	cout << "Welcome to my program!\n";
	int n,x,k;
	int i = 1;
	int sum = 0;
	float a = 0;
	float sum2 = 0;
	cout << " Please input n : ";
	cin >> n;
	a = n;
	cout << "1. " << causo1( n,sum) << endl;
	cout << "2. " << causo2( a,sum2) << endl;
	cout << "3. " << causo3(n) << endl;
	cout << " Please enter a value for x: ";
	cin >> x;
	cout << "4. " << causo4(n, x) << endl;
	int m = 2 * n;
	cout << "5. " << causo5(m, x) << endl;
	cout << "6.(fibonacci) " << causo6(n) << endl;
	cout << "7. Number found 1 : " << xn(n) << endl;
	cout << "   Number found 2: " << yn(n) << endl;
	cout << "8. " << causo8(n,i) << endl;
	cout << " Please input k: " << endl;
	cin >> k;
	if (k > n)
		cout << " cannot do this!!!!!!" << endl;
	else 
		cout << "9.  " << causo9(n,k) << endl;
	system("pause");
}