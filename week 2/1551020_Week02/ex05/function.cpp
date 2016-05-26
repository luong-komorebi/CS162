#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include "function.h"


void InputFromFile ( int &n , int* &a){
	
	ifstream file;	
	file.open("input.txt");
	file >>n;
	a= new int[n];
	if ( a!=NULL){
		for (int i=0; i<n ; i++){
			file >> a[i];
		}
	}
	file.close();
}
int LargestNumber(int n, int *a){
	int max= a[0];
	for ( int i=0; i<n; i++){
		if (a[i]> max)
			max = a[i];
	}
	return max;
}
void SortOddEven( int n, int* &a){
	for ( int i=0; i< n; i++){
			for ( int j=0; j < n ; j++){
				if ( a[i] % 2!=0 && a[j] % 2!=0 && a[j] > a[i] ){
					int temp =a[i];
					a[i]=a[j];
					a[j]=temp;
				}
				else if (a[i] % 2==0 && a[j] % 2==0 && a[j] < a[i]){
					int temp =a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
	}
for (int i=0; i<n; i++){
	cout << a[i] << "  ";
}
}
void Insert ( int n, int *a, int insert){
	int* b = new int[n+1];
	for ( int i = 0; i < n; i++){
		b[i]=a[i];
	}


	if ( abs( b[0] -insert ) %2 == 0){
		for ( int i=0; i < n ; i=i+2){
			if ( insert -b[i] > 0 ){
				for ( int j=n; j>i; j=j-1){
					b[j]=b[j-1];
				}
				b[i]=insert;
				break;
			}
			else continue;
		}
	}
	else 
		for ( int i=1; i < n ; i=i+2){
			if ( insert -b[i] > 0 ){
				n=n+1;
				for ( int j=n; j>i; j=j-1){
					b[j]=b[j-1];
				}
				b[i]=insert;
				break;
			}
			else continue;
		}
for (int i=0; i<n; i++){
	cout << b[i] << "  ";
}
}

