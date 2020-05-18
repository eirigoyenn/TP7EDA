#include <iostream>
#include "Compresor.h"
#include "Descompresor.h"

int main(void) {

	Compresor c;

	if (c.compress("Dados256.png"))
		cout << "OK" << endl;
	else
		cout << "FAILED" << endl;

	Descompresor desc;
	
	if (desc.decompress("compressedFile.EDA"))
		cout << "OK" << endl;
	else
		cout << "FAILED" << endl;

	return 0;
}