#include "Store.h"

void Store::addBill(Money bill){
	this->Bills.push_back(bill);
};

void Store::addComAccount(CommonAccount acc){
	this->CommonAccounts.push_back(acc);
};

void Store::addEnAccount(EnterpriseAccount acc){
	this->EnterpriseAccounts.push_back(acc);
};

void Store::addPremAccount(PremiumAccount acc){
	this->PremiumAccounts.push_back(acc);
};


std::vector<EnterpriseAccount> Store::getAllEnAccounts(){
	return this->EnterpriseAccounts;
};
std::vector<CommonAccount> Store::getAllComAccounts(){
	return this->CommonAccounts;
};
std::vector<PremiumAccount> Store::getAllPremAccounts(){
	return this->PremiumAccounts;
};

void Store::init() {
	std::vector<Money> allBills = conf.getMoney();
	for(int i = 0; i < allBills.size(); i++)
		this->Bills.push_back(allBills[i]);
};
