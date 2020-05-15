#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include "lodepng.h"

using namespace std;

typedef struct {
	unsigned int score;
	unsigned char Rprom;
	unsigned char Gprom;
	unsigned char Bprom;
} squareIteration;

class Compresor {

	enum {
		RINDEX,
		GINDEX,
		BINDEX
	};

public:
	Compresor();
	~Compresor();
	bool decodeFile(string file);
	bool compress(unsigned char* img, unsigned int w, unsigned int h, string res);
	squareIteration iterateSquare(unsigned char* img, unsigned int w, unsigned int h);

	unsigned char* img;
	unsigned int w, h;
	vector<string> files;
	vector<string> compFiles;
	string testing;
	unsigned int threshold;
private:


};