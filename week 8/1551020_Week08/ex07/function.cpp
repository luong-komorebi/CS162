#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;
void input(int ** banco, int  size, ifstream &fin) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fin >> banco[i][j];
		}
	}
}
void output(int ** banco, int  size, ofstream &fout) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fout << banco[i][j] << " ";
		}
		fout << endl;
	}
}
bool checkSafe(int** banco, int size, int row, int column, int number) {
	for (int i = 0; i < size; i++) {
		if (banco[i][column] == number) {
			return false;
		}

	}
	for (int i = 0; i < size; i++) {
		if (banco[row][i] == number) {
			return false;
		}
	}
	for (int i = 0; i <3; i++) {
		for (int j = 0; j < 3; j++) {
			if (banco[i + (row - row % 3)][j + (column - column % 3)]== number) {
				return false;
			}
		}
	}
	return true;
}
bool recursion(int ** banco, int size, int row, int column, int number) {
	if (checkAllComplete(banco, size, row, column) == true)
		return true;
	for ( number = 1; number < 10; number++){
		if (checkSafe(banco, size, row, column, number) == true) {
			banco[row][column] = number;
			if (recursion(banco, size, row, column, number) == true)
				return true;
			banco[row][column] = -1;
		}
	}
	return false;
}
bool checkAllComplete(int** banco, int size, int &row, int &column) {
	for (row = 0; row < 9; row++) {
		for (column = 0; column < 9; column++) {
			if (banco[row][column] == -1)
				return false;
		}
	}return true;
}