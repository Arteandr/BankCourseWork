#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <ios>
#include <map>

// Доступные языки в программе
enum Languages {
	RU,
	EN
};

class Config {
	private:
		Languages _lang;  												// Установленный язык
		std::string _currentPath;                                       // Текущий путь конфигурационного файла
		std::map<std::string, std::string> _data;                       // Значения с конфигурационного файла
	private:
		void checkConfigFile(std::fstream& FILE, std::string fileName); // Проверка конф. файла
	public:
		Config(); 														// Конструктор
		~Config();                                                      // Деструктор
	public:
		std::string getText(std::string fileName, unsigned short n);    // Получение текста из файла указаного в конф.
};


