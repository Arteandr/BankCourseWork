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
		Languages _lang;  // Установленный язык
		std::string _currentPath;
		std::map<std::string, std::string> _data;
	public:
		Config();
		~Config();
	public:
		void checkConfigFile(std::fstream& FILE, std::string fileName);
};


