#include "PremiumAccount.h"

unsigned short PremiumAccount::count = 0;
unsigned short PremiumAccount::billCount = 3;
unsigned short PremiumAccount::transferPercent = 0;

PremiumAccount::PremiumAccount(std::string username, long code)
	:Account(username, code){
		++count;
	};

PremiumAccount::PremiumAccount(std::string username, long code, std::vector<Money> bills)
	:Account(username, code, bills) { 
		++count;
	};

PremiumAccount::~PremiumAccount() {
	--count;
};
