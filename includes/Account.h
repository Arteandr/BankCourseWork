#pragma once

#include <fstream>
#include <string>

#include "Money.h"
#include "Config.h"

class Account {
	protected:
		struct MoneyList;
		MoneyList* head;
		MoneyList* teil;
		std::string username;
		long identCode;
	private:
		static unsigned short count;
	protected:
		struct MoneyList { Money money; MoneyList* next; };
	public:
		Account(std::string name, long ident, Money money);

		/*virtual void addMoney(long sum); 									// Положить деньги на счет
		virtual void withdrawMoney(long sum);								// Снять деньги со счета

		virtual void buildCashMoney(const Money& = Money());    // Создание нового счета
		virtual void deleteCashMoney(); 				                    // Удаление счета
		*/

		
		void setUsername(std::string); 										// Установка имени пользователя
		void setIdentCode(long code); 										// Установка идентиф. кода
		const std::string getUsername(); 									// Возвращает имя пользователя
		long getIdentCode(); 												// Возвращает идентиф. код

		static unsigned short getCount(); 									// Возвращает количество экземпляров
		// ТЗ
		void operator! (); 													// Обнуление всех счетов
		/*
		 
		friend std::fstream& operator << (std::fstream&,Account&); 			// Сохранение состояния в файл
		friend std::fstream& operator >> (std::fstream&,Account&);          // Считывание данных с файла
	
		virtual ~Account() = 0; */
};
