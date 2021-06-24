#pragma once

#include "Config.h"
#include "Store.h"
#include <ostream>
#include <string>
#include <iomanip>
#include <vector>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <functional>

/******************************* 
 * Класс для работы с фреймами
 * *******************************/ 
class Menu {
	public:
		std::function<void()> prevMenu;
	private:
		static void clear();   // Очистка консоли
	private:
		void footer();         // Футер фреймов
		void addAccount(std::string type);
		void addEnterpriseAccount(); 
		void delAccount(std::string type);
	public:
		Menu();     // Конструктор
		void chooseLang();     // Меню выбора языка
		void changeConfig();   // Меню изменения путей в конфигурационном файле
		void startScreen();    // Меню стартового экрана
		void mainScreen();     // Меню главного экрана
		void authorScreen();   // Меню об авторе
		void manualScreen();   // Меню руководства программы
		void infoScreen();     // Меню информации об программе 
		

		/* Меню работы с объектами */
		void stateObjScreen(); // Меню состояния объектов
		void addObjScreen();   // Меню добавления объектов
		void addAccountScreen(); // Меню добавления аккаунтов
		void addBillScreen();    // Меню добавления счета
		void delObjScreen();   // Меню удаления объектов
		void actObjScreen();   // Меню с действиями над объектами 
};
