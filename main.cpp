#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "address.h"
#include "date.h"
#include "student.h"

void loadStudents(std::vector<Student*> &students);
void printStudents(std::vector<Student*> &students);
void showStudentNames(std::vector<Student*> &students);
void findStudent(std::vector<Student*> &students);
void delStudents(std::vector<Student*> &students);
bool sortByFirst(Student*& a, Student*& b);
bool sortByLast(Student*& a, Student*& b);
bool sortByCredits(Student*& a, Student*& b);
void sortStudents(std::vector<Student*> &students);
void menu();

int main() {
	menu();
	return 0;
} // end main

void loadStudents(std::vector<Student*> &students) {
	std::ifstream inFile;
	std::string currentLine;
	inFile.open("students.csv");
	bool keepGoing = true;
	while (keepGoing) {
		getline(inFile, currentLine);
		if (inFile.eof()) {
                        keepGoing = false;
                } else {
			Student* student = new Student();
			student->init(currentLine);
			students.push_back(student);
		} // end if
	} // end while
	inFile.close();
} // end loadStudents

void printStudents(std::vector<Student*> &students) {
	for (Student*& student: students) {
		student->printStudent();
		std::cout << std::endl;
	} // end for
} // end printStudents

void showStudentNames(std::vector<Student*> &students) {
	for (Student*& student: students) {
		std::cout << student->getLastFirst() << ", " << student->getCredits() << std::endl;
	} // end for
	std::cout << std::endl;
} // end showStudentNames

void findStudent(std::vector<Student*> &students) {
	std::string search = "";
	std::cout << "last name of student: ";
	std::cin >> search;
	std::cout << std::endl;
	for (Student*& student: students) {
		int match = 0;
		match = student->getLast().find(search);
		if (match != -1) {
			student->printStudent();
			std::cout << std::endl;
		} // end if
	} // end for
} // end findStudent

void delStudents(std::vector<Student*> &students) {
	for (Student*& student: students) {
		delete student;
	} // end for
} // end delStudents

bool sortByFirst(Student*& a, Student*& b) {
	return a->getFirst() < b->getFirst();
} // end sortByFirst

bool sortByLast(Student*& a, Student*& b) {
	return a->getLast() < b->getLast();
} // end sortByLast

bool sortByCredits(Student*& a, Student*& b) {
	return a->getCredits() > b->getCredits();
} // end sortByCredits

void sortStudents(std::vector<Student*> &students) {
	std::string choice = "";
	std::cout << "1) sort by first name" << std::endl;
	std::cout << "2) sort by last name" << std::endl;
	std::cout << "3) sort by credit hours" << std::endl;
	std::cout << "please choose 1-3: ";
	std::cin >> choice;
	if (choice == "1") {
		std::sort(students.begin(), students.end(), sortByFirst);
	} else if (choice == "2") {
		std::sort(students.begin(), students.end(), sortByLast);
	} else if (choice == "3") {
		std::sort(students.begin(), students.end(), sortByCredits);
	} else {
		std::cout << "invalid input, please try again" << std::endl;
	} // end if
	std::cout << std::endl;
} // end sortStudents

void menu() {
	std::vector<Student*> students;
	loadStudents(students);
	std::string choice = "";
	bool keepGoing = true;
	while (keepGoing) {
		std::cout << "0) quit" << std::endl;
		std::cout << "1) print all student names" << std::endl;
		std::cout << "2) print all student data" << std::endl;
		std::cout << "3) find a student" << std::endl;
		std::cout << "4) sort students" << std::endl << std::endl;
		std::cout << "please choose 0-4: ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == "0") {
			keepGoing = false;
		} else if (choice == "1") {
			showStudentNames(students);
		} else if (choice == "2") {
			printStudents(students);
		} else if (choice == "3") {
			findStudent(students);
		} else if (choice == "4") {
			sortStudents(students);
		} else {
			std::cout << "invalid input, please try again" << std::endl;
		} // end if
	} // end while
	delStudents(students);
} // end menu
