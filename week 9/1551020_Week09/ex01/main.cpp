#include <iostream>
#include <fstream>
using namespace std;
void Copy(char filename1[], char filename2[]);
int main()
{
	char filename1[100];
	char filename2[100];
	cout << "Please input the source filename: ";
	cin.getline(filename1, 100);
	cout << "Please enter the destination filename: ";
	cin.getline(filename2, 100);
	Copy(filename1, filename2);

}
void Copy(char filename1[], char filename2[]) {
	fstream file1;
	fstream file2;
	file1.open(filename1, ios::in | ios::binary);
	file2.open(filename2, ios::out | ios::binary);
	char thisStringIsForCopy[10000];
	file1.read(thisStringIsForCopy, sizeof(thisStringIsForCopy));
	file2.write(thisStringIsForCopy, sizeof(thisStringIsForCopy));
	file1.close();
	file2.close();
}