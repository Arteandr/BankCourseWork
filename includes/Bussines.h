#pragma once

#include <string>

/******************************* 
 * Класс описывающий бизнес
 * *******************************/ 
class Bussines {
	private:
		static unsigned short count; 			// Количество экземпляров класса 
	protected:
		std::string bussinesName; 				// Название бизнеса
	public:
		Bussines(std::string name); 			// Конструктор

		static unsigned short getCount(); 		// Получение количества объектов класса
		std::string getBussinesName(); 			// Получения имени бизнеса 

		~Bussines();  							// Деструктор
};
