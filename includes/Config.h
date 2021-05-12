#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <ios>

// Доступные языки в программе
enum Languages {
	RU,
	EN
};

class Config {
	private:
		std::fstream _file; // Файл конфигурации	
		Languages _lang;  // Установленный язык

	public:
		Config(std::string fileName);
		void checkConfigFile(std::string fileName);
};


