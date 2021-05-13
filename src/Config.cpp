#include "Config.h"

// TODO: Custom exception class...

// Конструктор принимающий путь к файлу конфигурации.
Config::Config() {
	this->_currentPath = "../conf/config.txt" ;
	this->_lang = RU; 			     // Устанавливаем язык по умолчанию
	std::fstream FILE;
	this->checkConfigFile(FILE, this->_currentPath); // Открываем и проверяем конфигурационный файл

	this->printMap();
}

void Config::printMap() {
	for (const auto& [key,value] : this->_data) {
		std::cout << key << ":" << value << std::endl;
	}
}

// Проверка файла конфигурации
void Config::checkConfigFile(std::fstream& FILE, std::string fileName){
	if(FILE.is_open())
		FILE.close();

	try {
		FILE.open(fileName, std::ios_base::in | std::ios_base::out);
		if(!FILE.is_open())
			throw std::exception(); // Если файл не открылся выдаем исключение.

		std::string buffer;
		int count = 0;
		while(!FILE.eof()){
			getline(FILE, buffer);
			if(buffer.length() < 1)
				continue;
			else {
				++count;

				std::size_t pos = buffer.find("=");
				if(pos == std::string::npos)
					throw std::exception();

				std::string key = buffer.substr(0,pos);

				std::string value = buffer.substr(pos + 1);

				this->_data[key] = value;
			}
		}
		
		if(count != 2)
			throw std::exception();


	} catch(const std::exception& e) {
		this->_data.clear();
		FILE.close();
		if(this->_lang == RU)
			std::cerr << "Невозможно открыть файл конфигурации" << std::endl;
		else if(this->_lang == EN)
			std::cerr << "Configuration file not available" << std::endl;

		return;
	}

	FILE.seekg(0, std::ios_base::beg);
	FILE.close();
}

/*void Config::openFile(std::fstream& FILE, std::string fileName){
	std::string buffer;
	
	if(this->_lang == RU)
		fileName += "-ru";
	else if(this->_lang == EN)
		fileName += "-en";
	try {
		while (!FILE.eof()) {
			getline(FILE, buffer);
			std::string::size_type count = buffer.find(fileName);
			std::cout << count << " " << std::string::npos;	
			if(count == std::string::npos)
				continue;
			else{
				buffer = buffer.substr(count + fileName.size());
				count = buffer.find("=");
				if(count == std::string::npos)
					throw std::exception();

				buffer = buffer.substr(count + 1);
				
				FILE.seekg(0, std::ios_base::beg);
				break;
			}
		}
		if(FILE.eof())
			throw std::exception();

		FILE.close();
	}
	catch(const std::exception& e){
		FILE.close();

		if(this->_lang == RU)
			std::cerr << "Файл " << fileName << " не открыт." << std::endl;
		else if (this->_lang == EN)
			std::cerr << "File " << fileName << " was not open." << std::endl;
		return;	
	}
};*/









