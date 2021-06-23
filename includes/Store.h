#pragma once

#include "CommonAccount.h"
#include "EnterpriseAccount.h"
#include "Money.h"
#include "PremiumAccount.h"
#include <vector>

extern Config conf;

class Store {
	private:
		std::vector<Money> Bills;
		std::vector<EnterpriseAccount> EnterpriseAccounts;
		std::vector<CommonAccount> CommonAccounts;
		std::vector<PremiumAccount> PremiumAccounts;
	private:
		void addBill(Money bill);
		void addEnAccount(EnterpriseAccount acc);
		void addComAccount(CommonAccount acc);
		void addPremAccount(PremiumAccount acc);

		std::vector<EnterpriseAccount> getAllEnAccounts();
		std::vector<CommonAccount> getAllComAccounts();
		std::vector<PremiumAccount> getAllPremAccounts();
		std::vector<Money> getAllBills();

	public:
		void init();

};
