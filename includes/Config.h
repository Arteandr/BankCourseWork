#pragma once

#include "Money.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <ios>
#include <map>
#include <vector>

/******************************* 
 * Доступные языки в программе 
 * *******************************/ 
enum Languages {
	RU,
	EN
};

/******************************* 
 * Класс для работы с файлами
 * *******************************/ 
class Config {
	public:
		static unsigned short count;                                    // Количество экземпляров класса
	private:
		Languages _lang;  												// Установленный язык
		std::string _currentPath;                                       // Текущий путь конфигурационного файла
		std::map<std::string, std::string> _data;                       // Значения с конфигурационного файла
	public:
		Config();                                                       // Конструктор
		void checkConfigFile(); 										// Проверка конф. файла
		std::vector<std::string> getText(std::string fileName);         // Получение текста из файла указаного в конф.
		void setLanguage(Languages lang); 								// Установка языка программы
		void setCurrentPath(std::string path);                          // Установка текущего пути к конфигурационному файлу
		std::string getCurrentPath();                                   // Получение текущего пути конфигурацинного файла
		Money getMoney(int code);
		std::vector<Money> getMoney();

		std::vector<std::vector<std::string>> getAccounts(std::string type);

		std::vector<int> split(std::string);
};
