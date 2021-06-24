#include "Config.h"
#include "Menu.h"
#include "PremiumAccount.h"
#include "Store.h"

Config conf = Config(); // Создаем объект конфигурации
Store store = Store(); // Создаем объект для хранения данных
Menu menu = Menu(); // Создаем объект меню

int main(){
	conf.setCurrentPath("../conf/config.txt"); // Устанавливаем дефолтный путь к конфигурационному файлу
	conf.checkConfigFile(); // Открываем и проверяем конфигурационный файл

	store.init();

	conf.deleteAccount("common", 3);
	menu.startScreen();

	return 0;
};
