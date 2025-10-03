#include <iostream>
#include <sstream>
#include "date.h"

Date::Date() {
	Date::date = "";
	Date::day = 0;
	Date::month = 0;
	Date::year = 0;
} // end constructor

Date::~Date() {} // end deconstructor

void Date::init(std::string date) {
	Date::date = date;
	std::stringstream ss;
	std::string sMonth;
	std::string sDay;
	std::string sYear;
	ss.clear();
	ss.str(Date::date);
	getline(ss, sMonth, '/');
	getline(ss, sDay, '/');
	getline(ss, sYear);
	ss.clear();
	ss.str("");
	ss << sMonth;
	ss >> month;
	ss.clear();
	ss.str("");
	ss << sDay;
	ss >> day;
	ss.clear();
	ss.str("");
	ss << sYear;
	ss >> year;
} // end init

std::string Date::monthToString() {
	std::string stringMonth = "";
	if (Date::month == 1) {
		stringMonth = "January";
	} else if (Date::month == 2) {
		stringMonth = "February";
	} else if (Date::month == 3) {
		stringMonth = "March";
	} else if (Date::month == 4) {
		stringMonth = "April";
	} else if (Date::month == 5) {
		stringMonth = "May";
	} else if (Date::month == 6) {
		stringMonth = "June";
	} else if (Date::month == 7) {
		stringMonth = "July";
	} else if (Date::month == 8) {
		stringMonth = "August";
	} else if (Date::month == 9) {
		stringMonth = "September";
	} else if (Date::month == 10) {
		stringMonth = "October";
	} else if (Date::month == 11) {
		stringMonth = "November";
	} else {
		stringMonth = "December";
	} // end if
	return stringMonth;
} // end monthToString

void Date::printDate() {
	std::cout << monthToString() << " " << Date::day << ", " << Date::year << std::endl;
} // end printDate


