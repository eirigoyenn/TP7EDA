#include "Compresor.h"

Compresor::Compresor(){

	img = nullptr;
	w = 0;
	h = 0;
}


Compresor::~Compresor() {



}

bool Compresor::decodeFile(string file) {

	lodepng_decode32_file(&img, &w, &h, file.c_str());
	
	if (img == nullptr)
		return false;


	return true;

}




bool Compresor::compress() {







}

unsigned char Compresor::colorMax(char color, unsigned char*, unsigned int w, unsigned int h) {

	unsigned int index = 0;

	switch (color) {

	case RED:
		break;
		
	case GREEN: index += 1;
		break;

	case BLUE: index += 2;
		break;

	}



	for (int i = 0; i < w * h; i++) {

		 index += 4 * i ;
		

	}




}