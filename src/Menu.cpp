#include "Menu.h"

extern Config conf;

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


Menu::Menu() {
	this->prevMenu = nullptr;
};

// Очистка консоли
void Menu::clear() {
	std::system("clear");
};

void Menu::footer() {
	std::cout << std::endl;

	std::vector<std::string> info = conf.getText("FOOTER");

	for(int i = 0; i < info.size(); i++) {
		std::cout << info[i] << std::endl;
	};

	int key;
	bool err = false;

	do {
		err = false;
		key = getch();
		if(key != 127 && key != 9 && key != 27)
			err = true;
	} while(err);

	switch (key) {
		case 127:
			this->mainScreen();
			break;
		case 9:			
			this->chooseLang();
			break;
		case 27:
			exit(0);
			break;
	};
}

/*-------------Начальный экран-------------*/
void Menu::chooseLang() {
	Menu::clear();

	std::cout << "Выберите язык работы программы\t" << "\t|" << "\tSelect the language of the program" << std::endl;
	std::cout << "\t\t\t\t" << "\t|" << std::endl;
	std::cout << "1. Русский\t\t\t" << "\t|" << "\t1. Russian" << std::endl;
	std::cout << "2. Английский\t\t\t" << "\t|" << "\t2. English" << std::endl;

	bool err;
	int key;

	do { 
		err = false;
		key = getch();
		if(key != 49 && key != 50)
			err = true;
	
	} while(err);

	switch (key) {
		case 49:
			conf.setLanguage(RU);
			break;
		case 50:
			conf.setLanguage(EN);
			break;
	}
	
	this->prevMenu();
};

void Menu::startScreen() {
	this->prevMenu = [this]() { this->startScreen(); };

	Menu::clear();

	std::vector<std::string> info = conf.getText("START_SCREEN");

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

	this->mainScreen();
};
/******************************* 
 * 		Главный экран
 * *******************************/ 
void Menu::mainScreen() {
	this->prevMenu = [this]() { this->mainScreen(); };

	Menu::clear();

	std::vector<std::string> info = conf.getText("MAIN_SCREEN");

	for(int i = 0; i < info.size() - 1; i++) {
		std::cout << i << ". " << info[i] << std::endl;
	}

	std::cout << info.size() - 1 << ". " << info[info.size() - 1] << std::endl;
	bool err = false;
	int key;
	do {
		err = false;
		// 48 - 0 | 57 - 9
		key = getch();

		if(key < 48 || key > 57) {
			err = true;
		}
	} while(err);

/******************************* 
 * Комментарий [x]:
 * 	х - клавиша соответствующая номеру
 * 	*******************************/ 
	switch (key) {
		case 48: // 0
			this->stateObjScreen();
			break;
		case 49: // 1
			this->addObjScreen();
			break;
		case 50: // 2
			this->delObjScreen();
			break;
		case 51: // 3
			this->actObjScreen();
			break;
		case 52: // 4
			this->changeConfig();
			break;
		case 53: // 5
			this->chooseLang();
			break;
		case 54: // 6
			this->authorScreen();
			break;
		case 55: // 7
			this->manualScreen();
			break;
		case 56: // 8
			this->infoScreen();
			break;
		case 57: // 9
			exit(0);
			break;
	}
};

void Menu::authorScreen() {
	this->prevMenu = [this] () { this->authorScreen(); };
	Menu::clear();

	std::vector<std::string> info = conf.getText("AUTHOR");

	for(int i = 0; i < info.size(); i++) {
		std::cout << info[i] << std::endl;
	};

	this->footer();

};

void Menu::manualScreen() {
	this->prevMenu = [this] () { this->manualScreen(); };
	Menu::clear();

	std::vector<std::string> info = conf.getText("MANUAL");
	
	center(55, info[0]) << info[0] << std::endl << std::endl;
	for(int i = 1; i < info.size(); i++) {
		if(i == 1 || i == 3 || i == 6 || i == 9) {
			std::cout << '\t' << info[i] << ":" << std::endl;
			continue;
		};

		std::cout << info[i] << std::endl;
	};

	this->footer();
};

void Menu::addAccountScreen() {
	Menu::clear();

	std::vector<std::string> info = conf.getText("ADD_ACCOUNTS_SCREEN");
	std::vector<std::string> footer = conf.getText("FOOTER");

	std::cout << info[0] << std::endl;
	for(short i = 1; i < info.size(); i++) {
		std::cout << i << ". " << info[i] << std::endl;
	};
	std::cout << std::endl;
	for(short i = 0; i < footer.size(); i++) {
		std::cout << footer[i] << std::endl;
	};

	int key;
	bool err;

	do {
		err = false;
		key = getch();

		if(key != 49 && key != 50 && key != 127 && key != 9 && key != 27)
			err = true;
	}while(err);

	switch (key) {
		case 49:
			break;
		case 50:
			break;
		case 51:
			break;
		case 127:
			this->prevMenu();
			break;
		case 9:			
			this->chooseLang();
			break;
		case 27:
			exit(0);
			break;
	};

};

void Menu::addBillScreen() {
	Menu::clear();

	std::vector<std::string> info = conf.getText("ADD_BILLS_SCREEN");

	std::cout << info[0] << std::endl;
	// TODO: Добавить проверку на аккаунты
	if(true) {
		Menu::clear();
		std::cout << info[2] << std::endl;
	    this->footer();
	}
	else {
		long code;
		bool err;

		do {
			err = false;
			std::cout << info[1];
			std::cin >> code;

			if(!std::cin || code < 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				err = true;
			}
		}while(err);
	};
};


void Menu::addObjScreen() {
	this->prevMenu = [this] () { this->addObjScreen(); };
	
	Menu::clear();

	std::vector<std::string> info = conf.getText("ADD_OBJ_SCREEN");
	std::vector<std::string> footer = conf.getText("FOOTER");

	for(short i = 0; i < info.size(); i++) {
		std::cout << i + 1 << ". " << info[i] << std::endl;
	};
	std::cout << std::endl;
	for(short i = 0; i < footer.size(); i++) {
		std::cout << footer[i] << std::endl;
	};

	int key;
	bool err;

	do {
		err = false;
		key = getch();

		if(key != 49 && key != 50 && key != 127 && key != 9 && key != 27)
			err = true;
	}while(err);

	switch (key) {
		case 49:
			this->addAccountScreen();
			break;
		case 50:
			this->addBillScreen();
			break;
		case 127:
			this->mainScreen();
			break;
		case 9:			
			this->chooseLang();
			break;
		case 27:
			exit(0);
			break;
	};
};
