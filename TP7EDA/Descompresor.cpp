#include "Descompresor.h"

Descompresor::Descompresor() {

	w = 0;
	h = 0;
	img = nullptr;

}
Descompresor::~Descompresor() {



}

bool Descompresor::loadFile(const char* filename) {

	ifstream file;
	file.open(filename, ios_base::binary);

	w = getSize(file);
	h = w;
	
	char c = 0;
	while (file.get(c)) {

		std::cout << c ;
		decompressdFile.push_back(c);

	}

	return true;
}

bool Descompresor::decompress(string file) {




}

int Descompresor::getSize(ifstream& file) {

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

	return tam;
}