#include <iostream>
#include <sstream>
#include "address.h"
#include "date.h"
#include "student.h"

Student::Student() {
	Student::studentAddress = new Address();
	Student::birthDate = new Date();
	Student::gradDate = new Date();
	Student::firstName = "";
	Student::lastName = "";
	Student::creditHours = 0;
} // end constructor

Student::~Student() {
	delete Student::studentAddress;
	delete Student::birthDate;
	delete Student::gradDate;
} // end deconstructor

void Student::init(std::string studentString) {
	std::stringstream ss;
	ss.clear();
	ss.str(studentString);
	getline(ss, Student::firstName, ',');
	getline(ss, Student::lastName, ',');
	std::string street;
	std::string city;
	std::string state;
	std::string zip;
	getline(ss, street, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	Student::studentAddress->init(street, city, state, zip);
	std::string bDate;
	std::string gDate;
	getline(ss, bDate, ',');
	getline(ss, gDate, ',');
	Student::birthDate->init(bDate);
	Student::gradDate->init(gDate);
	std::string hours;
	getline(ss, hours);
	ss.clear();
	ss.str("");
	ss << hours;
	ss >> Student::creditHours;
} // end init

void Student::printStudent() {
	std::cout << Student::firstName << " " << Student::lastName << std::endl;
	Student::studentAddress->printAddress();
	std::cout << "DOB: ";
	Student::birthDate->printDate();
	std::cout << "Grad: ";
	Student::gradDate->printDate();
	std::cout << "Credits: " << Student::creditHours << std::endl;
	for (int i = 0; i < 36; i++) {
		std::cout << "_";
	} // end for
	std::cout << std::endl;
} // end printStudent

std::string Student::getFirst() {
	return Student::firstName;
} // end getFirst

std::string Student::getLast() {
	return Student::lastName;
} // end getLast

std::string Student::getLastFirst() {
	std::stringstream ss;
	ss << Student::lastName << ", " << Student::firstName;
	return ss.str();
} // end getLastFirst

int Student::getCredits() {
	return Student::creditHours;
} // end getCredits
