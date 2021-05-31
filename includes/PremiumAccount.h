#pragma once

#include "Account.h"
#include <string>

class PremiumAccount: public Account {
	private:
		static unsigned short billCount;
		static unsigned short count;
	protected:
		static unsigned short transferPercent;
	public:
		PremiumAccount(std::string username, long code);
};
