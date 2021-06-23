#include "Config.h"
#include "Menu.h"
#include "PremiumAccount.h"
#include "Store.h"

Config conf = Config(); // Создаем объект конфигурации
Menu menu = Menu(); // Создаем объект меню
Store store = Store(); // Создаем объект для хранения данных

int main(){
	conf.setCurrentPath("../conf/config.txt"); // Устанавливаем дефолтный путь к конфигурационному файлу
	conf.checkConfigFile(); // Открываем и проверяем конфигурационный файл

	store.init();
	std::vector<PremiumAccount> t = store.getAllPremAccounts();
	std::cout << t.size();

	menu.startScreen();

	return 0;
};
