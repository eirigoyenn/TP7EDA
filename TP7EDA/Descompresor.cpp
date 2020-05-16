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
	char size[3];
	size[0] = c;
	file.get(c);
	size[1] = c;
	file.get(c);
	size[2] = c;
	
	int p=stoi(size);
	std::cout << "  W="<< p<< endl;

	while (file.get(c)) {

		std::cout << c ;
		decompressdFile.push_back(c);

	}

	return true;
}
