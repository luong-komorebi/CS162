#include <iostream>
using namespace std;

int main(){
	int x, y ;
	int* p, *q;
	x=2;
	y=8;
	p= &x;
	q=&y;
	cout << " Address of x : " << p <<endl;
	cout <<" Value of x: " << *p <<endl;
	cout << " Value of p: " << p <<endl;
	cout <<" Value of *p : " << *p << endl;
	cout << " Address of y : " << q <<endl;
	cout <<" Value of y: " << *q <<endl;
	cout << " Value of p: " << q <<endl;
	cout <<" Value of *p : " << *q << endl;
	int** i ; 
	i = &p;
	cout << " The address of p : " << i << endl;
	int** i1;
	i1= &q;
	cout <<" THe address of q: " << i1 << endl;
	cout <<" The hex value of p: " << hex << p <<endl;
	cout <<" The hex value of q: " << hex << q <<endl;
	cout <<" The hex value of i ( points to the address of p): " << hex << i <<endl;
	cout <<" The hex value of i1( points to the address of q): " << hex << i1 <<endl;
	
	
	return 0;
}