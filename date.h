#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS
#include <iostream>

class Date {
	protected:
		std::string date;
		int day;
		int month;
		int year;
	public:
		Date();
		~Date();
		void init(std::string date);
		std::string monthToString();
		void printDate();
}; // end class def

#endif
