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

class Config {
	public:
		static unsigned short count;
	private:
		Languages _lang;  												// Установленный язык
		std::string _currentPath;                                       // Текущий путь конфигурационного файла
		std::map<std::string, std::string> _data;                       // Значения с конфигурационного файла
	public:
		void checkConfigFile(std::fstream& FILE, std::string fileName); // Проверка конф. файла
	public:
		Config();
	public:
		std::vector<std::string> getText(std::string fileName);         // Получение текста из файла указаного в конф.
		void setLanguage(Languages lang); 								// Установка языка программы
		void setCurrentPath(std::string path);
		std::string getCurrentPath();
};
