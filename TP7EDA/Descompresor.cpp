#include "Descompresor.h"

Descompresor::Descompresor() {

	w = 0;
	
	img = nullptr;

}
Descompresor::~Descompresor() {



}

bool Descompresor::loadFile(const char* filename) {

	ifstream file;
	file.open(filename, ios_base::binary);

	w = getSize(file);
	
	cout << "Wquellega=" << w << endl;
	fileData.resize(w * w * 4);
	
	char c = 0;
	while (file.get(c)) {

		decompressdFile.push_back(c);

	}

	return true;
}

bool Descompresor::decompress(const char* file) {

	loadFile(file);
	getData(0,w);

	return true;
}

void Descompresor::getData(unsigned int pos,unsigned int side) {

	decompressdFile[i]
	if()

}

void Descompresor::writeData(unsigned int pos, unsigned int side, unsigned char red, unsigned char green,unsigned char blue) {

	unsigned int i;
	for (i = 0; i < (side * side); i++) {

		fileData[pos + (4*i)] = red;
		fileData[pos + (4 * i) + 1] = green;
		fileData[pos + (4 * i) + 2] = blue;
		fileData[pos + (4 * i) + 3] = ALPHA;

	}

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