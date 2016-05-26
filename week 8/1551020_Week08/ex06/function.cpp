#include "function.h"
#include <iostream>
using namespace std;
void input(int ** banco,int  size) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			banco[i][j] = 0;
		}
	}
}
bool checkSafe(int** banco, int size,int x, int y) {
	if (x >= 0 && x <= size && y >= 0 && y <= size && banco[x][y] == 0)
		return true;
	else return false;
}
bool recursion(int** banco, int size, int movenumberi, int x, int y, int xMove[], int yMove[]) {
	if (movenumberi == (size+1)*(size+1)) //dieu kien dung cua recursion
		return true;
	for (int k = 0; k < 8; k++) {
		int nextx, nexty;
		nextx =x+ xMove[k];
		nexty =y+ yMove[k];
		if (checkSafe(banco, size, nextx, nexty)) {
			banco[nextx][nexty] = movenumberi;
			if (recursion(banco, size, movenumberi + 1, nextx, nexty, xMove, yMove)) {
				return true;
			}
			else
				banco[nextx][nexty] = 0;
		}
	}
	return false;
}
void output(int**banco, int size) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			cout << banco[i][j] << "  ";
		}
		cout << endl;
	}
}