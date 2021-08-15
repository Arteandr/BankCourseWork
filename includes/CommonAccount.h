#pragma once

#include "Account.h"
#include "Money.h"
#include <string>
#include <iostream>
#include <vector>

/******************************* 
 * Стандартный аккаунт пользователя
 * *******************************/ 
class CommonAccount : public Account { 
	private:
		static unsigned short count; 							// Количество экземпляров класса
	public:
		CommonAccount(std::string username, long identCode); 	// Конструктор
		CommonAccount(std::string username, long identCode, std::vector<Money> bills);


		static unsigned short getCount(); 						// Получение count
};
