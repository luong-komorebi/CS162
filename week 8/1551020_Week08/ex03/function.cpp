#include "function.h"
#include <iostream>
using namespace  std;
void toBinary(int x) {
	if (x == 0)
		return;
	if (x % 2 == 0) {
		cout << "0";
	}
	else cout << "1";
	toBinary(x / 10);
}
int sumOfDigits(int x) {
	if (x %10==x)
		return 1;
	else {
		return ((x%10)+ sumOfDigits(x/10));
	}
}