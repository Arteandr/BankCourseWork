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

		void initBills();
		void initPremium();
		void initEnterprise();
		void initCommon();


	public:
		std::vector<EnterpriseAccount> getAllEnAccounts();
		std::vector<CommonAccount> getAllComAccounts();
		std::vector<PremiumAccount> getAllPremAccounts();
		std::vector<Money> getAllBills();

		bool codeExist(long code);

		void addCommonAccount(CommonAccount acc);
		void addPremiumAccount(PremiumAccount acc);
		void addEnterpriseAccount(EnterpriseAccount acc);
		void addBill(Money bill);

		int getTotalCount();

		void init();
};
