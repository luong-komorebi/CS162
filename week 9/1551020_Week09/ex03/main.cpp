#include "function.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	fstream filebitmap;
	Header h;
	DIBHeader a;
	a.sizeofDIBHeader=0;
	a.bitmapwidth=0;
	a.bitmapheight=0;
	a.numberOfColorPane=0;
	a.colorDepth=0;
	a.compressionMethod=0;
	a.pixelArraySize=0;
	a.horizontalResolution=0;
	a.verticalResolution=0;
	a.numberOfColorsInColorPalette=0;
	a.numberOfImportantColorUsed=0;
	h.bfOffBits = 0;
	h.bfReserved1 = 0;
	h.bfReserved2 = 0;
	h.bfSize = 0;
	h.bfType[0] = NULL;
	h.bfType[1] =NULL;
	filebitmap.open("ukraine.bmp", ios::in | ios::binary);
	Bitmap(filebitmap, h,a);
	filebitmap.close();
	filebitmap.open("ukraine2.bmp", ios::out | ios::binary);
	ukraine(filebitmap);
	filebitmap.close();
	filebitmap.open("russia.bmp", ios::out | ios::binary);
	russia(filebitmap);
	filebitmap.close();

	system("pause");
	
		
}