#include "function.h"
#include <iostream>
using namespace std;

bool is_palindrome(int l, int r, char* s) {
	if (s[l] != s[r])
		return false;
	else if (l == r || l>r)
		return true;
	else {
		return is_palindrome(++l, --r, s);
	}
	
}