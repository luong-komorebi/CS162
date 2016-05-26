#include "function.h"
#include <iostream>
using namespace std;

int main() {
	int size;
	cout << " How many tiles x tiles do you want to have \n for example : 1 x 1 , 2 x 2.... / input a number only ?";
	cin >> size;
	size = size - 1;
	int** banco;
	banco = new int*[size];
	for (int i = 0; i <= size; i++)
		banco[i] = new int [size];
	input(banco, size);
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	int x = 0;
	int y = 0;
	int movenumberi = 1;
	if (recursion(banco, size, movenumberi, x, y, xMove, yMove)) {
		cout << "Here is your solution for the knight: " << endl;
		output(banco, size);
	}
	else cout << " No solution!";
	system("pause");
	return 0;
}