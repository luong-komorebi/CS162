#pragma once
#include <fstream>
using namespace std;
void input(int ** banco, int  size, ifstream &fin);
bool checkSafe(int** banco, int size, int row, int column, int number);
void output(int ** banco, int  size, ofstream &fout);
bool checkAllComplete(int** banco, int size, int &row, int &column);
bool recursion(int ** banco, int size, int row, int column, int number);