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
		static unsigned short billCount; 						// Количество допустимых счетов
		static unsigned short transferPercent; 					// Процент для перевода на другой счет
	public:
		CommonAccount(std::string username, long identCode); 	// Конструктор
		CommonAccount(std::string username, long identCode, std::vector<Money> bills);


		static unsigned short getCount(); 						// Получение count
};
