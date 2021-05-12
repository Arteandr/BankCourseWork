#include "Config.h"

Config::Config(std::string fileName){
	this->_lang = RU; 				// Устанавливаем язык по умолчанию
	this->openConfigFile(fileName); // Открываем конфигурационный файл
}


// Открытие файла конфигурации
void Config::openConfigFile(std::string fileName){
	if(this->_file.is_open())
		this->_file.close();

	try {
		this->_file.open(fileName, std::ios_base::in | std::ios_base::out);
		if(!this->_file.is_open())
			throw std::exception(); // Если файл не открылся выдаем исключение.

		std::string buffer;
		int count = 0;
		while(!this->_file.eof()){
			getline(this->_file, buffer);
			++count;
		}

		if(count - 1 != 2)
			throw std::exception();

	} catch(const std::exception& e) {
		this->_file.close();
		if(this->_lang == RU)
			std::cerr << "Невозможно открыть файл конфигурации" << std::endl;
		else if(this->_lang == EN)
			std::cerr << "Configuration file not available" << std::endl;

		return;
	}

	this->_file.seekg(0, std::ios_base::beg);
}


/*void Config::openFile(std::fstream &this->_file, std::string fileName){
	std::string buffer;

	if(this->_lang == RU)
		fileName += "-ru";
	else if(this->_lang == EN)
		fileName += "-en";
	
	try {
		while (!this->_file.eof()) {
			getline(this->_file, buffer);
			std::string::size_type count = buffer.find(fileName);
			if(count == std::string::npos)
				continue;
			else{
				buffer = buffer.substr(count + fileName.size());
				count = buffer.find("=");
				if(count == std::string::npos)
					throw;

				buffer = buffer.substr(count + 1);
				this->_file.seekg(0, std::ios_base::beg);
				break;
			}
		}
		if(this->_file.eof())
			throw;

		this->_file.close();
	}
	catch(const std::exception& e){
		this->_file.close();

		if(this->_lang == RU)
			std::cerr << "Файл " << fileName << " не открыт." << std::endl;
		else if (this->_lang == EN)
			std::cerr << "File " << fileName << " was not open." << std::endl;
		return;	
	}
};*/
