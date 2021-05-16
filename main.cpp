#include <iostream>

#include "Config.h"
#include "Menu.h"

int main(){
	Config conf(Menu::chooseLang()); // Создаем объект конфигурации
	Menu menu(conf);
	
	menu.startScreen();

	return 0;
};
