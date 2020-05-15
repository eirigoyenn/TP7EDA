#include <iostream>
#include "Compresor.h"

int main(void) {

	Compresor c;

	c.decodeFile("imagen.png");

	c.compress(c.img, c.w, c.h, "");

	cout << c.testing << endl;
	return 0;
}