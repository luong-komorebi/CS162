#pragma once
void input(int** banco, int size);
bool checkSafe(int** banco, int size, int x, int y);
bool recursion(int** banco, int size,int movenumberi, int x, int y, int xMove[], int yMove[]);
void output(int**banco, int size);