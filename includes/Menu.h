#pragma once

#include "Config.h"
#include <ostream>
#include <string>
#include <iomanip>
#include <vector>

class Menu {
	private:
		Config& _cfg;
	private:
		void clear();
	public:
		Menu(Config& cfg);
	public:
		void startScreen();
};
