#pragma once

#include "Config.h"
#include <ostream>
#include <string>
#include <iomanip>
#include <vector>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>

class Menu {
	private:
		Config& _cfg;
	private:
		static void clear();
	public:
		Menu(Config& cfg);
	public:
		static Languages chooseLang();
		void startScreen();
		void mainScreen();
};
