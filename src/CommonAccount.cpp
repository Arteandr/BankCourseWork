#include "CommonAccount.h"

unsigned short CommonAccount::billCount = 1;
unsigned short CommonAccount::transferPercent = 25;

CommonAccount::CommonAccount(std::string name, long code)
	: Account(name, code, Money()) {
};
