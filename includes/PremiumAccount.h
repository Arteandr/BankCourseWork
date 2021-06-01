#pragma once

#include "Account.h"
#include <string>

/******************************* 
 * Премиум аккаунт
 * *******************************/ 
class PremiumAccount: public Account {
	private:
		static unsigned short billCount; 					// Количество доступных счетов 
		static unsigned short count; 						// Количество экземпляров класса
	protected:
		static unsigned short transferPercent; 				// Процент перевода на другой аккаунт
	public:
		PremiumAccount(std::string username, long code);    // Конструктор

		~PremiumAccount(); 									// Деструктор 
};
