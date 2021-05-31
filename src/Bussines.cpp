#include "Bussines.h"

unsigned short Bussines::count = 0;

Bussines::Bussines(std::string name): bussinesName(name) {
	++count;
};

Bussines::~Bussines() {
	--count;
};

std::string Bussines::getBussinesName() {
	return this->bussinesName;
};

unsigned short Bussines::getCount() {
	return Bussines::count;
};
