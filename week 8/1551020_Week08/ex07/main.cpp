#include "function.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	int size = 9;
	int row = 0; int column = 0;
	int number = 1;
	int** banco;
	banco = new int*[size];
	for (int i = 0; i < size; i++)
		banco[i] = new int[size];
	input(banco, size, fin);
	fin.close();
	recursion(banco, size, row, column, number);
	fout.open("output.txt");
	output(banco, size, fout);
	fout.close();
	system("pause");
	return 0;
}
