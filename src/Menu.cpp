#include "Menu.h"

std::ostream& center(int v, std::string x) {
	std::cout << std::setw(v + x.length() / 2);
	return std::cout;
};

int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
};

Menu::Menu(Config& cfg) : _cfg(cfg) { };

// Очистка консоли
void Menu::clear() {
	std::system("clear");
};


/*-------------Начальный экран-------------*/
Languages Menu::chooseLang() {
	Menu::clear();

	std::cout << "Выберите язык работы программы | Select the language of the program" << std::endl;
	std::cout << "1. Русский | Russian" << std::endl;
	std::cout << "2. Английский | English" << std::endl;
	bool err;
	int key;

	do { 
		err = false;
		key = getch();
		if(key == 49 || key == 50) {
			switch (key) {
				case 49:
					return RU;
					break;
				case 50:
					return EN;
					break;
			}
		} else err = true;
	
	} while(err);


	return RU;
};

void Menu::startScreen() {
	Menu::clear();

	std::vector<std::string> info = this->_cfg.getText("START_SCREEN");

	center(49, info[0]) << info[0] << std::endl;
	center(51, info[1]) << info[1] << std::endl;
	for (short i = 0; i < 5; i++) {
		std::cout << std::endl;
	}
	center(51, info[2]) << info[2] << std::endl;
	center(53, info[3]) << info[3] << std::endl;
	for (short i = 0; i < 3; i++) {
		std::cout << std::endl;
	}
	center(81, info[4]) << info[4] << std::endl;
	center(80, info[5]) << info[5] << std::endl;
	std::cout << std::endl;
	center(81, info[6]) << info[6] << std::endl;
	center(80, info[7]) << info[7] << std::endl;
	for (short i = 0; i < 3; i++) {
		std::cout << std::endl;
	}
	center(50, info[8]) << info[8];
	for (short i = 0; i < 5; i++) {
		std::cout << std::endl;
	}

	getch();
};

/*-------------Главный экран-------------*/
void Menu::mainScreen() {
	
}
