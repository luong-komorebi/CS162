#include "function.h"
#include <iostream>
using namespace std;
int causo1( int n, int sum){
	
	while (n != 0) {
		sum += n;
		return causo1(n-1, sum);
	}
	return sum;
}
float causo2(float a, float sum2) {
	while (a != 0) {
		sum2 += (1 / a);
		return causo2(a - 1, sum2);
	}
	return sum2;
}
int causo3(int n) {
	if (n == 0) {
		return 1;
	}
	else return (n*causo3(n - 1));
}
int causo4(int n, int x) {
	if (n == 0) {
		return 1;
	}
	else return (x* causo4(n - 1, x));
}
int causo5(int n, int x) {
	if (n == 0) {
		return 0;
	}
	else {
		return (causo4(n, x)+causo5(n-2,x));
	}
}
int causo6(int n) {
	if (n == 0 || n == 1)
		return 1;
	else return( causo6(n - 1) + causo6(n - 2) );

}
int xn(int n) {
	if (n == 0) {
		return 1;
	}
	else return (xn(n - 1) + yn(n - 1));
}
int yn(int n) {
	if (n == 0)
		return 0;
	else return (3*xn(n-1)+2*yn(n-1));
}
int causo8(int n, int i) {
	if (n == 0) {
		return 1;
	}
	else {
		return (pow(i, 2)*causo8(n - 1,i+1));
	}
}
int causo9(int n, int k) {
	if ((k == n&& k==1)|| k==n) {
		return 1;
	}
	else {
		return ((causo3(n - 1) / (causo3(k - 1)*causo3(n - k))) + (causo3(n - 2) / (causo3(k - 2)*causo3(n - k))));
	}
}