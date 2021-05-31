#include "EnterpriseAccount.h"

unsigned short EnterpriseAccount::count = 0;

EnterpriseAccount::EnterpriseAccount(std::string username, long code, std::string bName)
	:PremiumAccount(username, code), Bussines(bName) {
		++count;
	};

EnterpriseAccount::~EnterpriseAccount() {
	--count;
};

unsigned short EnterpriseAccount::getCount() {
	return EnterpriseAccount::count;
};
