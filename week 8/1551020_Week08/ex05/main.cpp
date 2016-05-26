#include "function.h"
#include <iostream>
using namespace std;
int main() {
	int n;
	cout << " How many tiles x tiles do you want to have \n for example : 1 x 1 , 2 x 2.... / input a number only ?";
	cin >> n;
	n = n - 1;
	int **banco;
	int col = 0, row = 0;
	banco = new int*[n];
	for (int i = 0; i <= n; i++) {
		banco[i] = new int[n];
	}
	input(banco,n);
	if (recursion(banco, n, col) == true) {
		cout << " We can place " <<n+1<<" queens on "<<n+1<<" x "<<n+1<<" board like this : " << endl;
		output(banco, n);
	}
	else cout<< " We cannot place " << n+1 << " queens on " << n+1<< " x " << n+1 << " board" << endl;
	system("pause");
	return 0;
}