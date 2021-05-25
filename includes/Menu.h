#pragma once

#include "Config.h"
#include <ostream>
#include <string>
#include <iomanip>
#include <vector>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>
#include <functional>

// Класс для работы с фреймами программы
class Menu {
	public:
		std::function<void()> prevMenu;
	private:
		static void clear();   // Очистка консоли
	private:
		void footer();         // Футер фреймов
	public:
		Menu();     // Конструктор
		void chooseLang();     // Меню выбора языка
		void startScreen();    // Меню стартового экрана
		void mainScreen();     // Меню главного экрана
		void authorScreen();   // Меню об авторе

		/* Меню работы с объектами */
		void stateObjScreen(); // Меню состояния объектов
		void addObjScreen();   // Меню добавления объектов
		void delObjScreen();   // Меню удаления объектов
		void actObjScreen();   // Меню с действиями над объектами 
};
