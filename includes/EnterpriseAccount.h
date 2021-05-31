#pragma once

#include "PremiumAccount.h"
#include "Bussines.h"

class EnterpriseAccount final: public Bussines, public PremiumAccount {
	private:
		static unsigned short count;
		static unsigned short billCount;
	public:
		EnterpriseAccount(std::string username, long code, std::string bName);

		static unsigned short getCount();

		~EnterpriseAccount();
};
