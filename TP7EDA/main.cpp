#include <iostream>
#include "Compresor.h"
#include <fstream>

int main(void) {

	Compresor c;

	c.decodeFile("img.png");


	c.compress(c.img, c.w, c.h, to_string(c.h*c.w));

	fstream fs;
	fs.open("test.EDA");

	fs << c.testing;
	fs.close();
	cout << c.testing << endl;
	return 0;
}