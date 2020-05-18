#pragma once
#include "lodepng.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#define ALPHA 255

using namespace std;

class Descompresor
{
	enum {
		RINDEX,
		GINDEX,
		BINDEX
	};

public:

	Descompresor();
	~Descompresor();
	bool decompress(const char* file);
	void getData(unsigned int pos,unsigned int side);
	bool output();
	int getSize(ifstream& file);
	void writeData(unsigned int pos,unsigned int side, unsigned char red, unsigned char green, unsigned char blue);

private:

	//void generateDecompressedFile(unsigned char* img, unsigned int w, unsigned int h, vector<char>& res);
	//void outputFile();
	bool loadFile(const char* file);
	unsigned char* img;
	unsigned int w;
	size_t size;
	vector<char> decompressdFile;
	vector<unsigned  char>fileData;


};

