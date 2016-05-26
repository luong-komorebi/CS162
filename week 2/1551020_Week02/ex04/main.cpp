#include <iostream>
using namespace std;

int main(){
	int x,y,z;
	int* p,	*q,*r;
	x=1;
	y=2;
	z=3;
	p=&x;
	q=&y;
	r=&z;
	cout << " the value of x: '" << x << "'"<< endl;
	cout << " the value of y: '" << y << "'"<< endl;
	cout << " the value of z: '" << z << "'"<< endl;
	cout << " the value of p: '" << p << "'"<< endl;
	cout << " the value of q: '" << q << "'"<< endl;
	cout << " the value of r: '" << r << "'"<< endl;
	cout << " the value of *p: '" << *p << "'"<< endl;
	cout << " the value of *q: '" << *q << "'"<< endl;
	cout << " the value of *r: '" << *r << "'"<< endl;
	cout << " Swapping pointers \n";
	r = p; p = q; q = r;
	cout << " the value of x: '" << x << "'"<< endl;
	cout << " the value of y: '" << y << "'"<< endl;
	cout << " the value of z: '" << z << "'"<< endl;
	cout << " the value of p: '" << p << "'"<< endl;
	cout << " the value of q: '" << q << "'"<< endl;
	cout << " the value of r: '" << r << "'"<< endl;
	cout << " the value of *p: '" << *p << "'"<< endl;
	cout << " the value of *q: '" << *q << "'"<< endl;
	cout << " the value of *r: '" << *r << "'"<< endl;
	return 0;
}