#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include <iostream>
#include "address.h"
#include "date.h"

class Student {
	protected:
		Address* studentAddress;
		Date* birthDate;
		Date* gradDate;
		std::string firstName;
		std::string lastName;
		int creditHours;
	public:
		Student();
		~Student();
		void init(std::string studentString);
		void printStudent();
		std::string getLast();
		std::string getLastFirst();
		int getCredits();
}; // end class def

#endif
