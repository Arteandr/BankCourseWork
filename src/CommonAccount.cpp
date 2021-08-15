#include "CommonAccount.h"

unsigned short CommonAccount::count = 0;

CommonAccount::CommonAccount(std::string name, long code)
	: Account(name, code) {
		++count;
	};

CommonAccount::CommonAccount(std::string name, long code, std::vector<Money> bills)
	:Account(name, code, bills) {
		++count;
	};
