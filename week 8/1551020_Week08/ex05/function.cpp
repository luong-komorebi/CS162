#include "function.h"
#include <iostream>
using namespace std;
void input(int ** banco, int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			banco[i][j] = 0;
		}
	}
}
bool checkSafetoPut(int** banco, int n, int col, int row) {
	for (int i = 0; i < col; i++) {
		if (banco[row][i] != 0) //check left side
			return false;
	}
	for (int i = row, j = col; j >= 0 && i >=0; i--, j--) { //check upper left
		if (banco[i][j] != 0)
			return false;
	}
	for (int i = row, j = col; j >= 0 && i < n; i++, j--) {// check lower left
		if (banco[i][j] != 0)
			return false;
	} // no need to check right side because we move to the right
	return true;
}
bool recursion(int** banco, int n, int col) {
	int i = 0;
	if (col > n)
		return true; // dieu kien dung
	for (i=0; i <= n; i++) {
		if (checkSafetoPut(banco, n, col, i) == true) {
			banco[i][col] = 1;
			if (recursion(banco, n, col + 1) == true)  // cho nó chạy để check, nếu sai có nghĩa là k place n queen vào bàn cờ n x n ô được ( ở trường hợp này/)
				return true; // chỉ cần có 1 cột k thỏa là k nhảy dc tới đây, chạy xuống dưới backtrack, tăng i lên làm tiếp hàng tiếp theo.
			banco[i][col] = 0; //backtrack;
		}
	}
	return false;
}
void output(int** banco, int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << banco[i][j] << " ";
		}
		cout << endl;
	}
}