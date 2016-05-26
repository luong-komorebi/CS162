#pragma once
void input(int **banco, int n);
bool checkSafetoPut(int **banco, int n, int col, int row); //check if the tile is safe to put a queen inside
bool recursion(int** banco, int n, int col);
void output(int** banco, int n);