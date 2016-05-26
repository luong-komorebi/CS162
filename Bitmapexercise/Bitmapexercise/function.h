#include <fstream>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;
struct BmpSignature
{
	unsigned char data[2];
};

#pragma pack(1)
struct BmpHeader
{
	BmpSignature signature;
	unsigned long fileSize;
	unsigned long reserved;
	long dataOffset;
};

struct BmpDib
{
	unsigned long dibSize;
	unsigned long imageWidth;
	unsigned long imageHeight;
	unsigned short colorPlaneCount;
	unsigned short pixelSize;
	unsigned long compressMethod;
	unsigned long bitmapByteCount;
	unsigned long  horizontalResolution;
	unsigned long  verticalResolution;
	unsigned long colorCount;
	unsigned long importantColorCount;
};

struct Color
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

struct ColorTable
{
	Color	 *colors;
	unsigned long length;
};

struct PixelArray
{
	Color	 **pixels;
	unsigned long rowCount;
	unsigned long columnCount;
};
bool checkBMP(fstream &file);
void readBMPheader(fstream &file, BmpHeader &header);
void readBmpDib(fstream &file, BmpDib &dib);
void printBmpDib(BmpDib dib);
void printBmpHeader(BmpHeader header);
void readBmpPixelArray(fstream &file, BmpHeader header, BmpDib dib, PixelArray &data);
void scanBmpPixelLine(fstream &file, Color *&line, unsigned long length);
void skipBmpPadding(fstream &file, char count);

void drawBmp(BmpDib dib, PixelArray data);
void releaseBmpPixelArray(PixelArray data);