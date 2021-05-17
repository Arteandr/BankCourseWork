#include <iostream>

#include "Config.h"
#include "Menu.h"

int main(){
	Config conf = Config(); // Создаем объект конфигурации
	Menu menu = Menu(conf); // Создаем объект меню
	
	conf.setCurrentPath("../conf/config.txt"); // Устанавливаем дефолтный путь к конфигурационному файлу
	conf.checkConfigFile(conf.getCurrentPath()); // Открываем и проверяем конфигурационный файл

	menu.startScreen();

	return 0;
};
