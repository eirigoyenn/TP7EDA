#include <iostream>

#include "lodepng.h"

int main(void) {

	unsigned char* img;
	unsigned int w, h;

	lodepng_decode32_file(&img, &w, &h, "img.png");
	
	if (img != nullptr) {


		for (int i = 0; i < w * h; i++) {
			
			unsigned int c = 4 * i + 2;
			img[c] = 255;

		}

		lodepng_encode32_file("nuevaimagen.png", img, w, h);
		free(img);
	}

	return 0;
}