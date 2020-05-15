#include <iostream>
#include "Compresor.h"

int main(void) {

	Compresor c;

	if (c.compress("img.png"))
		cout << "OK" << endl;
	else
		cout << "FAILED" << endl;

	return 0;
}