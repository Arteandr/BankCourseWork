#include "Account.h"

unsigned short Account::count = 0;

// Constructor + destructor
Account::Account(std::string name, long ident, Money money)
:username(name), identCode(ident)
{
	this->bills.push_back(money);
	++count;
};

Account::Account(std::string name, long ident, std::vector<Money> bills){
	this->username = name;
	this->identCode = ident;
	for(int i = 0; i < bills.size(); i++)
		this->bills.push_back(bills[i]);

	++count;
};

// Overloads 
void Account::operator!() {
	std::list<Money>::iterator it;
	for(it = this->bills.begin(); it != this->bills.end(); ++it) {
		!(*it); // Оператор ! перегружен как обнуление счета
	};
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

unsigned short Account::getBillCount() {
	return this->bills.size();
};
