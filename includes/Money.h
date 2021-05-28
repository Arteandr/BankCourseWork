#pragma once

#include <string>

class Money {
	private:
		std::string currency; 					// Название валюты
		long summMoney; 						// Текущий счет
	public:
		Money(std::string c = "$", long s = 0);

		long getMoney() const;
		const std::string getName() const;      // Метод получения названия валюты

		void setName(std::string name);         // Метод установки названия валюты
		void setSumm(long summ);                // Установка суммы денег

		Money& operator +=(long summ); 			// Добавить сумму к текущей
		Money& operator -=(long summ); 			// Отнять сумму от текущей
		Money& operator !();                    // Метод обнуления счёта
		Money& operator =(std::string name); 	// Установка названия валюты


		static unsigned short getCount(); 		// Метод получения количества экземпляров класса

		~Money();
		static unsigned short count; 			// Количество экземпляров класса
};
