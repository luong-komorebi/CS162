#include "function.h"
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;

bool checkBMP(fstream &file) {
	if (file.fail()) {
		return false;
	}
	BmpSignature signature;
	file.read((char*)&signature, sizeof(signature));
	if (signature.data[0] == 'B' && signature.data[1] == 'M') {
		cout << " This is a bitmap file!";
	}
	else cout << " This is not a bitmapfile";
}

void readBMPheader(fstream &file, BmpHeader &header)
{
	file.read((char *)&header, sizeof(BmpHeader));
}

void printBmpHeader(BmpHeader header)
{
	cout << "*** BMP Header ***" << endl;
	cout << "- File Size  : " << header.fileSize << " byte(s)" << endl;
	cout << "- Reserved : " << header.reserved << endl;
	cout << "- Data Offset: " << header.dataOffset << " byte(s)" << endl;
}

void readBmpDib(fstream &file, BmpDib &dib)
{
	file.read((char *)&dib, sizeof(BmpDib));
}

void printBmpDib(BmpDib dib)
{
	cout << "*** BMP Dib ***\n";
	cout << "- DIB Size               : " << dib.dibSize << "byte(s)" << endl;
	cout << "- Image Width            : " << dib.imageWidth << endl;
	cout << "- Image Height           : " << dib.imageHeight << endl;
	cout << "- Number of Color Planes : " << dib.colorPlaneCount << endl;
	cout << "- Pixel Size             : " << dib.pixelSize << "bit(s)" << endl;
	cout << "- Compress Method        : " << dib.compressMethod << endl;
	cout << "- Bitmap Size            : " << dib.bitmapByteCount << "byte(s)" << endl;
	cout << "- Horizontal Resolution  : " << dib.horizontalResolution << endl;
	cout << "- Vertical Resolution    : " << dib.verticalResolution << endl;
	cout << "- Number of Colors       : " << dib.colorCount << endl;
	cout << "- Number of Impt Colors  : " << dib.importantColorCount << endl;
}

void readBmpPixelArray(fstream &file, BmpHeader header, BmpDib dib, PixelArray &data)
{
	data.rowCount = dib.imageHeight;
	data.columnCount = dib.imageWidth;
	data.pixels = new Color*[data.rowCount];

	char paddingCount = (4 - (dib.imageWidth * (dib.pixelSize / 8) % 4)) % 4;

	file.seekg(header.dataOffset, ios::beg);

	for (int i = 0; i < data.rowCount; i++)
	{
		scanBmpPixelLine(file, data.pixels[data.rowCount - i - 1], dib.imageWidth);
		skipBmpPadding(file, paddingCount);
	}
}

void scanBmpPixelLine(fstream &file, Color *&line, unsigned long length)
{
	line = new Color[length];
	file.read((char *)line, length*sizeof(Color));
}

void skipBmpPadding(fstream &file, char count)
{	
	if (count == 0)
		return;

	char padding[3];
	file.read((char *)&padding, count);
}

void drawBmp(BmpDib dib, PixelArray data)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);

	for (int i = 0; i < dib.imageHeight; i++)
		for (int j = 0; j < dib.imageWidth; j++)
		{
			Color pixel = data.pixels[i][j];
			SetPixel(hdc, j, i, RGB(pixel.red, pixel.green, pixel.blue));
		}

	ReleaseDC(console, hdc);
}

void releaseBmpPixelArray(PixelArray data)
{
	for (int i = 0; i < data.rowCount; i++)
		delete[]data.pixels[i];

	delete[]data.pixels;
}