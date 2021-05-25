#include <cstdio>
#include <iostream>

#include "Config.h"
#include "Menu.h"

Config conf = Config(); // Создаем объект конфигурации

int main(){
	Menu menu = Menu(); // Создаем объект меню
	
	conf.setCurrentPath("../conf/config.txt"); // Устанавливаем дефолтный путь к конфигурационному файлу
	conf.checkConfigFile(); // Открываем и проверяем конфигурационный файл

	menu.startScreen();

	return 0;
};
