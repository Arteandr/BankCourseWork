#include "Config.h"
#include "FileException.h"
#include <cstdlib>
#include <string>

// Количество объектов класса
unsigned short Config::count = 0;
// Конструктор класса Config
Config::Config() {
	++count;
};

// Чтение файла конфигурации
void Config::checkConfigFile(){
	std::fstream FILE;
	try {
		FILE.open(this->_currentPath, std::ios_base::in | std::ios_base::out);
		if(!FILE.is_open())
			throw FileOpenError();

		std::string buffer;
		int count = 0;
		while(!FILE.eof()){
			getline(FILE, buffer);
			if(buffer.length() < 1 || buffer[0] == '#')
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

		if(this->_data["LANG"] == "RU")
			this->_lang = RU;
		else if(this->_data["LANG"] == "EN")
			this->_lang = EN;
		else
			this->_lang = RU;

	} catch(FileOpenError& e) {
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при открытии файла: ";
				break;
			case EN:
				std::cerr << "Error during opening the file: ";
				break;
		}
		std::cout << this->_currentPath << std::endl;
		return;
	} catch(FileRowReadError& e){
		switch (this->_lang) {
			case RU:
				std::cerr << "Ошибка при чтении строки из файла: ";
				break;
			case EN:
				std::cerr << "String read error";
				break;
		}
		std::cout << this->_currentPath << std::endl;
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
		std::cout << this->_currentPath << std::endl;
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
			if(buffer.length() < 1 || buffer[0] == '#')
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
				std::cerr << "Wrongо number of lines in file: ";
				break;
		}
		std::cout << fileName << std::endl;
	}
	return s;
};

Money Config::getMoney(int code) {
	std::fstream FILE;
	std::string buffer;
	std::string needStr = "[" + std::to_string(code) + "]";
	std::string bCurr;
	long bSum;

	try {
		FILE.open(this->_data["BILLS_STATE"]);
		if(!FILE.is_open())
			throw FileOpenError();

 		while(!FILE.eof()) {
			getline(FILE, buffer);
			std::size_t pos = buffer.find(needStr);
			if(pos == std::string::npos)
				continue;
			else {
				getline(FILE, buffer);
				pos = buffer.find("=");
				bCurr = buffer.substr(pos + 1);
				
				getline(FILE, buffer);
				pos = buffer.find("=");
				bSum = std::stol(buffer.substr(pos + 1));

				break;
			};
		};
	} catch(std::exception) { }

	return Money(bCurr, bSum);
};

std::vector<Money> Config::getMoney() {
	std::fstream FILE;
	std::string buffer;
	std::vector<Money> bBills;
	std::string bCurr;
	long bSum;

	try {
		FILE.open(this->_data["BILLS_STATE"]);
		if(!FILE.is_open())
			throw FileOpenError();

		while(!FILE.eof()){
			getline(FILE, buffer);
			std::size_t pos = buffer.find("[");
			if(pos == std::string::npos)
				continue;
			else {
				getline(FILE, buffer);
				pos = buffer.find("=");
				bCurr = buffer.substr(pos + 1);
				
				getline(FILE, buffer);
				pos = buffer.find("=");
				bSum = std::stol(buffer.substr(pos + 1));

				Money mn = Money(bCurr, bSum);

				bBills.push_back(mn);
				continue;
			};
		};
	} catch(std::exception ex) {
		std::cout << "Exception" << ex.what();
	};

	return bBills;
};

std::vector<int> Config::split(std::string s) {
	std::vector<int> numbers;
	std::string delimiter = ",";

	std::size_t pos = 0;
	std::string token;
	while((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		numbers.push_back(std::stoi(token));
		s.erase(0, pos + delimiter.length());
	};
	numbers.push_back(std::stoi(s));

	return numbers;
};

std::vector<std::vector<std::string>> Config::getAccounts(std::string type) {
	std::fstream FILE;
	std::string buffer;
	std::vector<std::vector<std::string>> bAcc;
	std::string bBills;
	std::string bUsername;
	std::string bIdent;
	std::string bBussines;

	try {
		FILE.open(this->_data[type]);
		if(!FILE.is_open())
			throw FileOpenError();

		while(!FILE.eof()){
			getline(FILE, buffer);
			std::size_t pos = buffer.find("[");
			if(pos == std::string::npos)
				continue;
			else {
				std::vector<std::string> temp;

				bIdent = buffer.substr(pos + 1);
				bIdent.erase(bIdent.size() - 1);
				temp.push_back(bIdent);

				getline(FILE, buffer);
				pos = buffer.find("=");
				bBills = buffer.substr(pos + 1);
				temp.push_back(bBills);

				getline(FILE,buffer);
				pos = buffer.find("=");
				bUsername = buffer.substr(pos + 1);
				temp.push_back(bUsername);

				if(type == "ENTERPRISE_STATE"){
					getline(FILE, buffer);
					pos = buffer.find("=");
					bBussines = buffer.substr(pos + 1);
					temp.push_back(bBussines);
				};
		
				bAcc.push_back(temp);
			};
		};
	} catch(std::exception ex) 
	{
		std::cout << "Exception: " << ex.what();
	};

	return bAcc;
};

void Config::addBill(long code, std::string currency) {
	std::fstream FILE;
	
	try {
			FILE.open(this->_data["BILLS_STATE"], std::ios::app);
			if(!FILE.is_open())
				throw FileOpenError();

		FILE << "[" << code << "]" << std::endl;
		FILE << "currency=" << currency << std::endl;
		FILE << "sum=0" << std::endl;

		FILE.close();
	} catch(std::exception ex) {
		std::cout << "Exception addBill";
	};
};

void Config::addAccount(std::string type, std::string username, long ident){
	std::fstream FILE;
	
	try {
		if(type == "premium"){
			FILE.open(this->_data["PREMIUM_STATE"], std::ios::app);
			if(!FILE.is_open())
				throw FileOpenError();
		}else if(type == "common") {
			FILE.open(this->_data["COMMON_STATE"], std::ios::app);
			if(!FILE.is_open())
				throw FileOpenError();
		};

		FILE << "[" << ident << "]" << std::endl;
		FILE << "bills=1" << std::endl;
		FILE << "username=" << username << std::endl;

		FILE.close();
	} catch(std::exception ex) {
		std::cout << "Exception addAccount";
	};
};

void Config::addEnterpriseAccount(std::string username, long ident, std::string bName) {
	std::fstream FILE;
	
	try {
		FILE.open(this->_data["ENTERPRISE_STATE"], std::ios::app);
		if(!FILE.is_open())
			throw FileOpenError();

		this->addBill(ident, "Рубли");

		FILE << "[" << ident << "]" << std::endl;
		FILE << "bills=" << ident << std::endl;
		FILE << "username=" << username << std::endl;
		FILE << "bussinesName=" << bName << std::endl;

		FILE.close();
	} catch(std::exception ex) {
		std::cout << "Exception addAccount";
	};


};

/*---------------Getters and Setters---------------*/
// Установка текущего языка
void Config::setLanguage(Languages lang) {
	std::string buffer;
	std::fstream FILE;

	try {
		this->_lang = lang;
		FILE.open(this->_currentPath, std::ios_base::in | std::ios_base::out);

		if(!FILE.is_open())
			throw FileOpenError();

		while(!FILE.eof()) {
			getline(FILE, buffer);
			if(buffer.length() < 1 || buffer[0] == '#')
				continue;
			else {
				std::size_t pos = buffer.find("LANG");
				if(pos == std::string::npos)
					continue;

				std::string l;
				if(lang == RU)
					l = "RU";
				else if(lang == EN)
					l = "EN";
			
				FILE.seekp(pos);
				
				buffer = "LANG=" + l + '\n';
				FILE << buffer;
			}
		};

	} catch(std::exception& e) { std::cout << "Error"; };

	FILE.close();
};

// Установка текущего пути файла конфигурации
void Config::setCurrentPath(std::string path) {
	this->_currentPath = path; 
};

// Получение текущего пути файла конфигурации
std::string Config::getCurrentPath() {
	return this->_currentPath;
}
