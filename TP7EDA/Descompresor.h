#pragma once
#include "lodepng.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

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
	bool decompress(string file);
	bool loadFile(const char* file);
	int getSize(ifstream& file);

private:

	//bool loadFile(string file);
	//void generateDecompressedFile(unsigned char* img, unsigned int w, unsigned int h, vector<char>& res);
	//void outputFile();
	unsigned char* img;
	unsigned int w, h;
	vector<char> decompressdFile;
	

};

