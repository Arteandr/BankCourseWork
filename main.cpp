#include <iostream>

#include "Config.h"
#include "Menu.h"

int main(){
	Config conf = Config(); // Создаем объект конфигурации
	Menu menu(conf);

	menu.startScreen();

	return 0;
};
