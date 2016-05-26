#pragma once
#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;
#pragma pack(1)
struct Header {
	char bfType[2];           /* Magic number for file */ // text to hex 424d
	unsigned int   bfSize;           /* Size of file */
	unsigned short bfReserved1;      /* Reserved */
	unsigned short bfReserved2;      /* ... */
	unsigned int   bfOffBits;
};
struct DIBHeader {
	unsigned int sizeofDIBHeader;
	unsigned int bitmapwidth;
	unsigned int bitmapheight;
	unsigned short numberOfColorPane;
	unsigned short colorDepth;
	unsigned int compressionMethod;
	unsigned int pixelArraySize;
	unsigned int horizontalResolution;
	unsigned int verticalResolution;
	unsigned int numberOfColorsInColorPalette;
	unsigned int numberOfImportantColorUsed;
};
struct pixel{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};
void Bitmap(fstream &filebitmap, Header h, DIBHeader a);
void ukraine(fstream &filebitmap);
void russia(fstream &filebitmap);
