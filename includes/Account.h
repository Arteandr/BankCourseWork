#pragma once

#include <fstream>
#include <string>
#include <list>
#include <vector>

#include "Money.h"
#include "Config.h"

/*******************************
 * Абстрактный класс аккаунта
 * *******************************/ 
class Account {
	protected:
		std::list<Money> bills; 											// Доступные счета на аккаунте
		std::string username; 												// Имя аккаунта
		long identCode; 													// Идентификационный код
	private:
		static unsigned short count; 										// Количество экземпляров класса
	public:
		Account(std::string name, long ident, Money money = Money());
		Account(std::string name, long ident, std::vector<Money> bills);
		/*virtual void addMoney(long sum); 									// Положить деньги на счет
		virtual void withdrawMoney(long sum);								// Снять деньги со счета

		virtual void deleteCashMoney(); 				                    // Удаление счета
		*/

		void setUsername(std::string); 										// Установка имени пользователя
		void setIdentCode(long code); 										// Установка идентиф. кода
		const std::string getUsername(); 									// Возвращает имя пользователя
		long getIdentCode(); 												// Возвращает идентиф. код
		unsigned short getBillCount();

		static unsigned short getCount(); 									// Возвращает количество экземпляров
		void operator! (); 													// Обнуление всех счетов

		/*
		friend std::fstream& operator << (std::fstream&,Account&); 			// Сохранение состояния в файл
		friend std::fstream& operator >> (std::fstream&,Account&);          // Считывание данных с файла
	
		virtual ~Account() = 0; */
};
