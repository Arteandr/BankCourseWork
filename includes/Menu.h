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

// Класс для работы с фреймами программы
class Menu {
	private:
		Config& _cfg;          // Ссылка на конфигурацию
	private:
		static void clear();   // Очистка консоли
	public:
		Menu(Config& cfg);     // Конструктор
		void chooseLang();     // Меню выбора языка
		void startScreen();    // Меню стартового экрана
		void mainScreen();     // Меню главного экрана
};
