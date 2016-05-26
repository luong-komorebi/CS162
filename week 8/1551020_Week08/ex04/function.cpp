#include "function.h"
#include <iostream>
using namespace std;
void input(int a[30], int &count) {
	int i = 0;
	cout << " Input now ( 0 to exit) : ";
	do {
		cin >> a[i];
		cout << a[i] << "  inputted!" << endl;
		i++;
	} while (a[i-1] != 0);
	count = i;
}
void output(int a[30]) {
	int i = 0;
	for (int i = 0; a[i] != 0; i++) {
		cout << a[i] << " ";
	}
}
void outputinreversed(int a[30]) {
	int i = 0;
	while (true) {
		if (a[i] == 0) {
			for (int j = i-1; j >=0; j--)
				cout << a[j] << " ";
			break;
		}
		i++;
	}
}
int sumpositive(int a[30], int m) {
	if (a[m] == 0)
		return 0;
	else {
		if (a[m] % 2 == 0)
			return (a[m] + sumpositive(a, m + 1));
		else {
			return(sumpositive(a, m + 1));
		}
	}
	
}
int countDistinct(int a[], int n, int soluong){
		if (n == 0)
			return soluong;
		for (int i = 0; i < n; ++i)
			if (a[i] == a[n])
			{
				soluong--;
				break;
			}
		return countDistinct(a, n - 1,soluong);
}
bool checkOdd(int a[], int count) {
	if (a[count] % 2 != 0)
		return 1;
	else return checkOdd(a, count - 1);
}
int checkMax(int a[], int n, int soluong) {
	if (n == 0)
		return soluong;
	for (int i = 0; i < n; ++i)
		if (a[i] >soluong)
		{
			soluong=a[i];
			break;
		}
	return checkMax(a, n - 1, soluong);
}
void sort(int a[], int count) {
	int maxIndex = 0, temp = 0, index = 0;
	for (index = maxIndex; index < count; index++) {
		if (a[index] > a[maxIndex]) {
			maxIndex = index;
		}
	}
	temp = a[count - 1];
	a[count - 1] = a[maxIndex];
	a[maxIndex] = temp;

	if (count > 1) {
		sort(a, --count);
	}
}