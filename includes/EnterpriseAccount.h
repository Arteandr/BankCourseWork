#pragma once

#include "Money.h"
#include "PremiumAccount.h"
#include "Bussines.h"
#include <vector>

/******************************* 
 * Аккаунт для бизнеса
 * *******************************/ 
class EnterpriseAccount final: public Bussines, public PremiumAccount {
	private:
		static unsigned short count; 											// Количество экземпляров класса 
	public:
		EnterpriseAccount(std::string username, long code, std::string bName);  // Конструктор
		EnterpriseAccount(std::string username, long code, std::string bName, std::vector<Money> bills);


		static unsigned short getCount(); 										// Получение количества экземпляров класса

		~EnterpriseAccount();                            						// Деструктор
};
