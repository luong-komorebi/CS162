#include<iostream>
#include "function.h"
using namespace std;
int main() {
	int n;
	cout << " How many characters do you want to input ? ";
	cin >> n;
	char* s = new char[n + 1];
	cin.get();
	if (n % 2 != 0){
		cout << " Your input cant be palindrome!";
		system("pause");
		return 0;
	}
	cout << " Please input them now ! ";
	cin.getline(s, n+1);
	int l = 0;
	int r = n-1;
	if (is_palindrome(l,r,s))
		cout << " The input is palindrome!";
	else cout << " The input is not palindrome!";
	system("pause");
	return 0;
}