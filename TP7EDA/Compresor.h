#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include "lodepng.h"

using namespace std;
class Compresor {

	enum {
		RED,GREEN,BLUE
	};

public:
	Compresor();
	~Compresor();
	bool decodeFile(string file);
	bool compress();
	unsigned char colorMax(char color,unsigned char* ,unsigned int w, unsigned int h);


private:
	unsigned char* img;
	unsigned int w,h;
	vector<string> files;
	vector<char*> compFiles;
	unsigned int threshold;

};