#include "function.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	fstream file;
	file.open("bitmap.bmp", ios::in | ios::binary);
	BmpHeader header;
	BmpDib dib;
	PixelArray data;
	Color *line;
	readBMPheader(file, header);
	readBmpDib(file, dib);
	readBmpPixelArray(file, header, dib, data);
	if (checkBMP(file))
	{
		printBmpHeader(header);
		printBmpDib(dib);
		system("pause");
		drawBmp(dib, data);
		releaseBmpPixelArray(data);
	}
	file.close();
	system("pause");
}