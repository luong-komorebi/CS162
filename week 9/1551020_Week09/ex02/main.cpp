#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

void Split(char* src, int numberOfParts) {
	int size, a, tmp;
	char* inp, name[15], *tmC;
	fstream fi, fo;
	fi.open(src, ios::in | ios::binary);
	fi.seekg(0, fi.end);
	size = fi.tellg();
	fi.seekg(0, fi.beg);
	inp = new char[size];
	fi.read(inp, size);
	fi.close();
	name[0] = '\0';
	name[0] = 'F';
	name[1] = 'i';
	name[2] = 'l';
	name[3] = 'e';
	name[4] = '0';
	name[5] = '1';
	name[6] = '.';
	name[7] = 't';
	name[8] = 'x';
	name[9] = 't';
	name[10] = '\0';
	for (int i = 0; i < numberOfParts; i++) {
		a = i + 1;
		name[4] = a / 10 + '0';
		name[5] = a % 10 + '0';
		fo.open(name, ios::out | ios::binary | ios::trunc);
		tmC = inp + (size * i) / numberOfParts;
		tmp = size * (i + 1) / numberOfParts - size * i / numberOfParts;
		fo.write((char*)tmC, tmp);
		fo.close();
	}
	delete[] inp;
}

void Merge(char *filename, int numberOfParts, char *dest) {
	ifstream ftext;
	fstream fi, fo;
	char* inp, name[15];
	int size;
	ftext.open(filename);
	fo.open(dest, ios::out | ios::binary | ios::trunc);
	while (!ftext.eof()) {
		ftext.getline(name, 11);
		fi.open(name, ios::in | ios::binary);
		fi.seekg(0, ios_base::end);
		size = fi.tellg();
		inp = new char[size];
		fi.seekg(0, ios_base::beg);
		fi.read(inp, size);
		fo.write(inp, size);
		delete[] inp;
		fi.close();
		numberOfParts--;
		if (numberOfParts == 0) break;
	}
	ftext.close();
	fo.close();
}

int main() {
	Split("input.txt", 15);
	Merge("list.txt", 7, "output.txt");
	return 0;
}