#pragma once

#include "Account.h"
#include "Money.h"
#include <string>
#include <iostream>

/******************************* 
 * Стандартный аккаунт пользователя
 * *******************************/ 
class CommonAccount : public Account { 
	public:
		static unsigned short billCount; 						// Количество допустимых счетов
		static unsigned short transferPercent; 					// Процент для перевода на другой счет
		CommonAccount(std::string username, long identCode); 	// Конструктор
};
