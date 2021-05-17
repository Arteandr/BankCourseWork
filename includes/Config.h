#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <ios>
#include <map>
#include <vector>

// Доступные языки в программе
enum Languages {
	RU,
	EN
};

// Класс для работы с файлами
class Config {
	// Статические поля
	public:
		static unsigned short count;                                    // Количество экземпляров класса

	// Приватные поля
	private:
		Languages _lang;  												// Установленный язык
		std::string _currentPath;                                       // Текущий путь конфигурационного файла
		std::map<std::string, std::string> _data;                       // Значения с конфигурационного файла

	// Публичные методы
	public:
		Config();                                                       // Конструктор
		void checkConfigFile(std::string fileName); // Проверка конф. файла
		std::vector<std::string> getText(std::string fileName);         // Получение текста из файла указаного в конф.
		void setLanguage(Languages lang); 								// Установка языка программы
		void setCurrentPath(std::string path);                          // Установка текущего пути к конфигурационному файлу
		std::string getCurrentPath();                                   // Получение текущего пути конфигурацинного файла
};
