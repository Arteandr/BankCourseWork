#include "Account.h"

unsigned short Account::count = 0;

Account::Account(std::string name, long ident, Money money)
:username(name), identCode(ident), head(nullptr), teil(nullptr)
{
	//	this->buildCashMoney(money);
	++count;
};

void Account::operator!() {
	this->teil = this->head;
	while(this->teil->next) {
		!(this->teil->money);
		this->teil = teil->next;
	};
	!(this->teil->money);
};



// Geters && Setters
void Account::setUsername(std::string name) {
	this->username = name;
};

void Account::setIdentCode(long code) {
	this->identCode = code;
};

const std::string Account::getUsername() {
	return this->username;
};

long Account::getIdentCode() {
	return this->identCode;
};

unsigned short Account::getCount() {
	return Account::count;
};
