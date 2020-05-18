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
	size = w * w*4;
	fileData.resize(w * w * 4);
	cout << fileData.size() << endl;
	
	char c = 0;
	while (file.get(c)) {

		decompressdFile.push_back(c);

	}

	return true;
}

bool Descompresor::decompress(const char* file) {

	bool result = true;

	loadFile(file);
	getData(0,w);
	result = output();

	return result;
}

void Descompresor::getData(unsigned int pos, unsigned int side) {

	if (side == 0) {
		return;
	}
	
	unsigned char value = decompressdFile.front();
	decompressdFile.erase(decompressdFile.begin());
	
	if (value == 0) {
		unsigned char red = decompressdFile.front();
		decompressdFile.erase(decompressdFile.begin());
		unsigned char green = decompressdFile.front();
		decompressdFile.erase(decompressdFile.begin());
		unsigned char blue = decompressdFile.front();
		decompressdFile.erase(decompressdFile.begin());
		writeData(pos, side, red, green, blue);
			return;
	} else if (value == 1) {
		getData(pos, side / 2);
		getData(pos + 4 * (side / 2), side / 2);
		getData(pos + 4 * (w * (side / 2)), side / 2);
		getData(pos + 4 * (w * (side / 2) + (side / 2)), side / 2);
	}
}

void Descompresor::writeData(unsigned int pos, unsigned int side, unsigned char red, unsigned char green ,unsigned char blue) {

	unsigned int i;
	for (i = 0; i <side; i++) {
		for (int j = 0; j < side; j++) {
			int offset = (j + i * w) * 4;
			fileData[pos + offset] = red;
			fileData[pos + offset + 1] = green;
			fileData[pos + offset + 2] = blue;
			fileData[pos + offset + 3] = 255;
		}
	}
}

bool Descompresor::output() {
	bool result = true;
	unsigned char* image = (unsigned char *) malloc(fileData.size()* (sizeof(unsigned char)));
	
	if (image == nullptr) {
		result = false;
		cout << "MALLOC FAIL" << endl;
		return result;
	}

	for (unsigned int i = 0; i < fileData.size(); i++) {
		image[i] = fileData[i];
	}
	const unsigned char filename[11] = "imagen.png";

	lodepng_encode32_file("imagenNueva.png", image, w, w);

	free(image);
	return result;
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