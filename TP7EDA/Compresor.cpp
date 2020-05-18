#include "Compresor.h"
#include <iostream>
Compresor::Compresor(){

	img = nullptr;
	w = 0;
	h = 0;
	threshold = 200;
}


Compresor::~Compresor() {
	free(img);
}


bool Compresor::compress(string file) {

	if (decodeFile(file)) {
		generateCompressedFile(img, w, h, compressdFile);
		outputFile();

		return true;
	}
	else {
		return false;
	}
}

bool Compresor::decodeFile(string file) {

	unsigned char error = lodepng_decode32_file(&img, &w, &h, file.c_str());
	
	if (img == nullptr || error)
		return false;

	return true;

}


void Compresor::generateCompressedFile(unsigned char* img, unsigned int w, unsigned int h, vector<char>& res) {

	squareIteration sqi = iterateSquare(img, w, h);
	
	if (sqi.score <= threshold) {
		res.push_back(0);
		res.push_back(sqi.Rprom);
		res.push_back(sqi.Gprom);
		res.push_back(sqi.Bprom);
		return;
	}

	if (w == 1 || h == 1) {
		res.push_back(0);
		res.push_back(sqi.Rprom);
		res.push_back(sqi.Gprom);
		res.push_back(sqi.Bprom);
		return;
	}

	res.push_back(1);
	generateCompressedFile(img, w / 2, h / 2, res);
	generateCompressedFile(img + (w / 2) + 1, w / 2, h / 2, res);
	generateCompressedFile(img + ((w) * (h / 2)) + 1, w / 2, h / 2, res);
	generateCompressedFile(img + (w * (h / 2) + (w / 2)) + 1, w / 2, h / 2, res);
}


squareIteration Compresor::iterateSquare(unsigned char* img, unsigned int w, unsigned int h) {
	
	squareIteration res;

	unsigned char Rmax = 0;
	unsigned char Rmin = 255;
	unsigned char Gmax = 0;
	unsigned char Gmin = 255;
	unsigned char Bmax = 0;
	unsigned char Bmin = 255;

	unsigned long Rprom = 0;
	unsigned long Gprom = 0;
	unsigned long Bprom = 0;
	
	for (int i = 0; i < w * h; i++) {

		Rprom += img[4 * i + RINDEX];
		Gprom += img[4 * i + GINDEX];
		Bprom += img[4 * i + BINDEX];

		 if (img[4 * i + RINDEX] > Rmax){
			 Rmax = img[4 * i + RINDEX];
		 }
		 else if (img[4 * i + RINDEX] < Rmin) {
			 Rmin = img[4 * i + RINDEX];
		 }

		if (img[4 * i + GINDEX] > Gmax) {
			Gmax = img[4 * i + GINDEX];
		}
		else if (img[4 * i + GINDEX] < Gmin) {
			Gmin = img[4 * i + GINDEX];
		}

		if (img[4 * i + BINDEX] > Bmax) {
			Bmax = img[4 * i + BINDEX];
		}
		else if (img[4 * i + BINDEX] < Bmin) {
			Bmin = img[4 * i + BINDEX];
		}

	}

	res.score = Rmax + Gmax + Bmax - Rmin - Gmin - Bmin;
	res.Rprom = Rprom / (w * h);
	res.Gprom= Gprom / (w * h);
	res.Bprom = Bprom / (w * h);

	return res;
}

void Compresor::outputFile() {
	ofstream myfile;
	myfile.open("compressedFile.EDA", ios_base::binary);
	cout <<"Winicial=" <<w << endl;
	
	saveSize(myfile);
	
	for (auto c : compressdFile) {
		
		myfile << c;
	}
	myfile.close();
}


void Compresor::saveSize(ofstream& myfile) {

	unsigned int* width = &w;
	unsigned char temp;
	temp = *((char*)width);
	myfile << temp;
	temp = *((char*)width + 1);
	myfile << temp;
	temp = *((char*)width + 2);
	myfile << temp;
	temp = *((char*)width + 3);
	myfile << temp;

}