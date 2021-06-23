#include "Store.h"

std::vector<EnterpriseAccount> Store::getAllEnAccounts(){
	return this->EnterpriseAccounts;
};
std::vector<CommonAccount> Store::getAllComAccounts(){
	return this->CommonAccounts;
};
std::vector<PremiumAccount> Store::getAllPremAccounts(){
	return this->PremiumAccounts;
};
std::vector<Money> Store::getAllBills(){
	return this->Bills;
};

void Store::addCommonAccount(CommonAccount acc) {
	this->CommonAccounts.push_back(acc);
};

void Store::addPremiumAccount(PremiumAccount acc) {
	this->PremiumAccounts.push_back(acc);
};

void Store::addEnterpriseAccount(EnterpriseAccount acc) {
	this->EnterpriseAccounts.push_back(acc);
};

void Store::addBill(Money bill) {
	this->Bills.push_back(bill);
};

void Store::initBills() {
	// Инициализирование всех счетов
	std::vector<Money> allBills = conf.getMoney();
	for(int i = 0; i < allBills.size(); i++)
		this->Bills.push_back(allBills[i]);
};


void Store::initPremium() {
	std::vector<std::vector<std::string>> pAcc = conf.getAccounts("PREMIUM_STATE");
	for(int i = 0; i < pAcc.size(); i++){
		std::vector<Money> bills;

		std::vector<int> billNumbers = conf.split(pAcc[i][1]);
		for(int j = 0; j < billNumbers.size(); j++) {
			bills.push_back(conf.getMoney(billNumbers[j]));	
		};

		PremiumAccount temp = PremiumAccount(pAcc[i][2],std::stol(pAcc[i][0]),bills);
		this->PremiumAccounts.push_back(temp);
	};
};

void Store::initCommon() {
	std::vector<std::vector<std::string>> pAcc = conf.getAccounts("COMMON_STATE");
	for(int i = 0; i < pAcc.size(); i++){
		std::vector<Money> bills;

		std::vector<int> billNumbers = conf.split(pAcc[i][1]);
		for(int j = 0; j < billNumbers.size(); j++)
			bills.push_back(conf.getMoney(billNumbers[j]));	

		CommonAccount temp = CommonAccount(pAcc[i][2],std::stol(pAcc[i][0]),bills);

		this->CommonAccounts.push_back(temp);
	};
	
};

void Store::initEnterprise() {
	std::vector<std::vector<std::string>> pAcc = conf.getAccounts("ENTERPRISE_STATE");
	for(int i = 0; i < pAcc.size(); i++){
		std::vector<Money> bills;

		std::vector<int> billNumbers = conf.split(pAcc[i][1]);
		for(int j = 0; j < billNumbers.size(); j++)
			bills.push_back(conf.getMoney(billNumbers[j]));	
		
		EnterpriseAccount temp = EnterpriseAccount(pAcc[i][2],std::stol(pAcc[i][0]),pAcc[i][3]);
	
		this->EnterpriseAccounts.push_back(temp);
	};
};

void Store::init() {
	this->EnterpriseAccounts.clear();
	this->CommonAccounts.clear();
	this->Bills.clear();
	this->PremiumAccounts.clear();

	this->initBills();
	this->initPremium();
	this->initCommon();
	this->initEnterprise();
};

int Store::getTotalCount() {
	return this->CommonAccounts.size() + this->EnterpriseAccounts.size() + this->PremiumAccounts.size() + this->Bills.size();
};
