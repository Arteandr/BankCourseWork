#pragma once

#include <string>

class Bussines {
	private:
		static unsigned short count;
	protected:
		std::string bussinesName;
	public:
		Bussines(std::string name);

		static unsigned short getCount();
		std::string getBussinesName();

		~Bussines();
};
