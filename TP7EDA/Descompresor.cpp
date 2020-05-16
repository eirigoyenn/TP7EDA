#include "Descompresor.h"

Descompresor::Descompresor() {



}
Descompresor::~Descompresor() {



}

bool Descompresor::loadFile(const char* filename) {

	ifstream file;
	file.open(filename, ios_base::binary);
	char c = 0;
	file.get(c);
	char size[4];
	size[0] = c;
	file.get(c);
	size[1] = c;
	file.get(c);
	size[2] = c;
	file.get(c);
	size[3] = c;
	
	int tam = *((int*)size);
	std::cout << "  W="<< tam<< endl;

	while (file.get(c)) {

		std::cout << c ;
		decompressdFile.push_back(c);

	}

	return true;
}
