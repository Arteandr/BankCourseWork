#include "Money.h"

unsigned short Money::count = 0;


// Constructor + Destructor
Money::~Money() {
	--Money::count;
};

// Reloads
Money& Money::operator+=(long summ) {
	this->summMoney = summ;
	return *this;
};

Money& Money::operator!() {
	this->summMoney = 0;
	return *this;
};

Money& Money::operator-=(long summ) {
	this->summMoney = this->summMoney - summ;
	return *this;
};

Money& Money::operator=(std::string name) {
	this->currency = name;
	return *this;
};


// Getters && setters 
long Money::getMoney() const {
	return this->summMoney;
};

const std::string Money::getName() const {
	return this->currency;
};

void Money::setName(std::string name) {
	this->currency = name;
};

void Money::setSumm(long summ) {
	this->summMoney = summ;
};

unsigned short Money::getCount() {
	return Money::count;
};
