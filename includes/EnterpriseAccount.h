#pragma once

#include "PremiumAccount.h"
#include "Bussines.h"

/******************************* 
 * Аккаунт для бизнеса
 * *******************************/ 
class EnterpriseAccount final: public Bussines, public PremiumAccount {
	private:
		static unsigned short count; 											// Количество экземпляров класса 
		static unsigned short billCount; 										// Количество доступных счетов
	public:
		EnterpriseAccount(std::string username, long code, std::string bName);  // Конструктор

		static unsigned short getCount(); 										// Получение количества экземпляров класса

		~EnterpriseAccount();                            						// Деструктор
};
