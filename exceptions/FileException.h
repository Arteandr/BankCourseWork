#pragma once

#include <exception>

class FileOpenError : std::exception {
	public:
		const char * what() const noexcept override {
			return "Ошибка при открытии файла: ";
		}
};

class FileRowReadError : std::exception {
	public:
		const char * what() const noexcept override {
			return "Ошибка при чтении строки из файла: ";
		}
};

class FileRowCountError : std::exception {
	public:
		const char * what() const noexcept override {
			return "Неверное количество строк в файле: ";
		}
};
