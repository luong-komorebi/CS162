#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;
void Bitmap(fstream &filebitmap, Header h, DIBHeader a) {
	if (filebitmap.fail()) {
		return;
	}
	filebitmap.read((char*)&h, sizeof(h));
	if (h.bfType[0] == 'B' && h.bfType[1] == 'M') {
		cout << " This is a bitmap file!";
	}
	else cout << " This is not a bitmapfile";
	filebitmap.read((char*)&a, sizeof(a));
	cout << " Size : " << h.bfSize << endl;
	cout << " Width : " << a.bitmapwidth << endl;
	cout << " Height : " << a.bitmapheight << endl;
	cout << " Color Depth: " << a.colorDepth << endl;
	cout << " Resolution: " << a.horizontalResolution << " x " << a.verticalResolution << endl;
}
void ukraine(fstream &filebitmap) {
	Header h1;
	h1.bfType[0] = 'B';
	h1.bfType[1] = 'M';
	h1.bfSize = 900 * 600 * 3 + 54;
	h1.bfReserved1 = 0;
	h1.bfReserved2 = 0;
	h1.bfOffBits = 54;
	DIBHeader a1;
	a1.bitmapheight = 900;
	a1.bitmapwidth = 600;
	a1.colorDepth = 24;
	a1.sizeofDIBHeader = 40;
	a1.numberOfColorPane = 1;
	a1.numberOfColorsInColorPalette = 0;
	a1.compressionMethod = 0;
	a1.pixelArraySize = 900 * 600;
	a1.horizontalResolution = 2835;
	a1.verticalResolution = 2835;
	a1.numberOfImportantColorUsed = 0;
	pixel** ukraine = new pixel*[600];
	for (int i = 0; i < 600; i++) {
		ukraine[i] = new pixel[900];
	}
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 900; j++) {
			ukraine[i][j].blue = 190;
			ukraine[i][j].green = 81;
			ukraine[i][j].red = 5;
		}
	}
	for (int i = 300; i < 600; i++) {
		for (int j = 0; j < 900; j++) {
			ukraine[i][j].blue = 0;
			ukraine[i][j].green = 217;
			ukraine[i][j].red = 255;
		}
	}
	filebitmap.write((char*)&h1, sizeof(h1));
	filebitmap.write((char*)&a1, sizeof(a1));
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j <900; j++) {
			filebitmap.write((char*)&ukraine[i][j], sizeof(ukraine[i][j]));
		}
	}

}
void russia(fstream &filebitmap) {
	Header h1;
	h1.bfType[0] = 'B';
	h1.bfType[1] = 'M';
	h1.bfSize = 900 * 600 * 3 + 54;
	h1.bfReserved1 = 0;
	h1.bfReserved2 = 0;
	h1.bfOffBits = 54;
	DIBHeader a1;
	a1.bitmapheight = 900;
	a1.bitmapwidth = 600;
	a1.colorDepth = 24;
	a1.sizeofDIBHeader = 40;
	a1.numberOfColorPane = 1;
	a1.numberOfColorsInColorPalette = 0;
	a1.compressionMethod = 0;
	a1.pixelArraySize = 900 * 600;
	a1.horizontalResolution = 2835;
	a1.verticalResolution = 2835;
	a1.numberOfImportantColorUsed = 0;
	pixel** ukraine = new pixel*[600];
	for (int i = 0; i < 600; i++) {
		ukraine[i] = new pixel[900];
	}
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 900; j++) {
			ukraine[i][j].blue = 30;
			ukraine[i][j].green = 43;
			ukraine[i][j].red = 213;
		}
	}
	for (int i = 200; i < 400; i++) {
		for (int j = 0; j < 900; j++) {
			ukraine[i][j].blue = 166;
			ukraine[i][j].green = 57;
			ukraine[i][j].red = 0;
		}
	}
	for (int i = 400; i < 600; i++) {
		for (int j = 0; j < 900; j++) {
			ukraine[i][j].blue = 255;
			ukraine[i][j].green = 255;
			ukraine[i][j].red = 255;
		}
	}
	filebitmap.write((char*)&h1, sizeof(h1));
	filebitmap.write((char*)&a1, sizeof(a1));
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j <900; j++) {
			filebitmap.write((char*)&ukraine[i][j], sizeof(ukraine[i][j]));
		}
	}
}
