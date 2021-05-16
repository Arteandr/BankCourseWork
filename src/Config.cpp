#include "Config.h"
#include "FileException.h"

// TODO: Custom exception class...

// Конструктор принимающий путь к файлу конфигурации.
Config::Config(Languages lang) {
	this->_currentPath = "../conf/config.txt" ;
	this->_lang = lang; 			     // Устанавливаем язык по умолчанию
	std::fstream FILE;
	this->checkConfigFile(FILE, this->_currentPath); // Открываем и проверяем конфигурационный файл
}

// Проверка файла конфигурации
void Config::checkConfigFile(std::fstream& FILE, std::string fileName){
	if(FILE.is_open())
		FILE.close();

	try {
		FILE.open(fileName, std::ios_base::in | std::ios_base::out);
		if(!FILE.is_open())
			throw FileOpenError();

		std::string buffer;
		int count = 0;
		while(!FILE.eof()){
			getline(FILE, buffer);
			if(buffer.length() < 1)
				continue;
			else {
				std::size_t pos = buffer.find("=");
				if(pos == std::string::npos)
					throw FileRowReadError();

				std::string key = buffer.substr(0,pos);
				std::string value = buffer.substr(pos + 1);

				this->_data[key] = value;

				++count;
			}
		}
		if(count != 2)
			throw FileRowCountError();


	} catch(FileOpenError& e) {
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при открытии файла: ";
				break;
			case EN:
				std::cerr << "Error during opening the file: ";
				break;
		}
		std::cout << fileName << std::endl;
		return;
	} catch(FileRowReadError& e){
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при чтении строки из файла: ";
				break;
			case EN:
				std::cerr << "";
				break;
		}
		std::cout << fileName << std::endl;
		return;
	} catch(FileRowCountError& e) {
		switch (this->_lang) {
			case RU:
				std::cerr << "Неверное количество строк в файле: ";
				break;
			case EN:
				std::cerr << "Wrong number of lines in file: ";
				break;
		}
		std::cout << fileName << std::endl;
		return;
	}

	FILE.seekg(0, std::ios_base::beg);
	FILE.close();
}

// Получаем текст для отрисовки меню
std::vector<std::string> Config::getText(std::string fileName) {
	std::vector<std::string> s;

	if(this->_lang == RU)
		fileName += "_RU";
	else if(this->_lang == EN)
		fileName += "_EN";


	try {
		std::string value = this->_data[fileName];
		if(value.length() < 1)
			throw FileRowReadError();

		std::fstream FILE;
		FILE.open(value, std::ios_base::in | std::ios_base::out);
		if(!FILE.is_open())
			throw FileOpenError();

		std::string buffer;
		unsigned int cnt = 0;
		while(!FILE.eof()){
			getline(FILE, buffer);
			if(buffer.length() < 1)
				continue;
			else {
				s.push_back(buffer);;
				cnt++;
			}
		}

		if(cnt == 0)
			throw FileRowCountError();

		return s;

	}  catch(FileOpenError& e) {
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при открытии файла: ";
				break;
			case EN:
				std::cerr << "Error during opening the file: ";
				break;
		}
		std::cout << fileName << std::endl;
	} catch(FileRowReadError& e){
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при чтении строки из файла: ";
				break;
			case EN:
				std::cerr << "";
				break;
		}
		std::cout << fileName << std::endl;
	} catch(FileRowCountError& e) {
		switch (this->_lang) {
			case RU:
				std::cerr << "Неверное количество строк в файле: ";
				break;
			case EN:
				std::cerr << "Wrong number of lines in file: ";
				break;
		}
		std::cout << fileName << std::endl;
	}
	return s;
};
















