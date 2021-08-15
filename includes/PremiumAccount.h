#pragma once

#include "Account.h"
#include "Money.h"
#include <string>
#include <vector>

/******************************* 
 * Премиум аккаунт
 * *******************************/ 
class PremiumAccount: public Account {
	private:
		static unsigned short count; 						// Количество экземпляров класса
	public:
		PremiumAccount(std::string username, long code);    // Конструктор
		PremiumAccount(std::string username, long code, std::vector<Money> bills);

		~PremiumAccount(); 									// Деструктор 
};
