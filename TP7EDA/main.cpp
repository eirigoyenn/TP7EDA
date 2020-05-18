#include <iostream>
#include "Compresor.h"
#include "Descompresor.h"

int main(void) {

	Compresor c;

	if (c.compress("img.png"))
		cout << "OK" << endl;
	else
		cout << "FAILED" << endl;

	Descompresor desc;
	
	if (desc.decompress("img.png"))
		cout << "OK" << endl;
	else
		cout << "FAILED" << endl;

	return 0;
}