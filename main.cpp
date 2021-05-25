#include <cstdio>
#include <iostream>

#include "Config.h"
#include "Menu.h"

Config conf = Config(); // Создаем объект конфигурации
Menu menu = Menu(); // Создаем объект меню


int main(){
	
	conf.setCurrentPath("../conf/config.txt"); // Устанавливаем дефолтный путь к конфигурационному файлу
	conf.checkConfigFile(); // Открываем и проверяем конфигурационный файл

	menu.startScreen();

	return 0;
};
