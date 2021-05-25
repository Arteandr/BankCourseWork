#include "Money.h"

Money& Money::operator!() {
	this->summMoney = 0;
	return *this;
};
