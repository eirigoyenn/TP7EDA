#include "Compresor.h"

Compresor::Compresor(){

	img = nullptr;
	w = 0;
	h = 0;
	threshold = 100000;
}


Compresor::~Compresor() {
	free(img);
}

bool Compresor::decodeFile(string file) {

	lodepng_decode32_file(&img, &w, &h, file.c_str());
	
	if (img == nullptr)
		return false;

	return true;

}




void Compresor::compress(unsigned char* img, unsigned int w, unsigned int h, string res) {

	squareIteration sqi = iterateSquare(img, w, h);
	
	if (sqi.score <= threshold) {
		testing += res + "0" + to_string(sqi.Rprom) + to_string(sqi.Gprom) + to_string(sqi.Bprom);
		return;
	}

	if (w == 1 || h == 1) {
		testing += res + "0" + to_string(sqi.Rprom) + to_string(sqi.Gprom) + to_string(sqi.Bprom);
		return;
	}

	compress(img, w / 2, h / 2, res + "1");
	compress(img + (w / 2) + 1, w / 2, h / 2, res + "1");
	compress(img + ((w) * (h / 2)) + 1, w / 2, h / 2, res + "1");
	compress(img + (w * (h / 2) + (w / 2)) + 1, w / 2, h / 2, res + "1");
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