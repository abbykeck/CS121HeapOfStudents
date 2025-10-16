#include <iostream>
#include <fstream>
#include <vector>
#include "address.h"
#include "date.h"
#include "student.h"

/*
void testAddress();
void testDate();
void testStudent();
*/
void loadStudents(std::vector<Student*> &students);
void printStudents(std::vector<Student*> &students);
void showStudentNames(std::vector<Student*> &students);
void findStudent(std::vector<Student*> &students);
void delStudents(std::vector<Student*> &students);
void menu();

int main(){
	/*
	testDate();
	testAddress();
	testStudent();
	*/
	menu();
	return 0;
} // end main

/*
void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst() << std::endl;
  std::cout << "Credits: " << student->getCredits() << std::endl;
  delete student;
} // end testStudent
*/
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
} // end showStudentNames

void findStudent(std::vector<Student*> &students) {
	std::string search = "";
	std::cout << "last name of student: ";
	std::cin >> search;
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

void menu() {
	std::vector<Student*> students;
	loadStudents(students);
	std::string choice = "";
	bool keepGoing = true;
	while (keepGoing) {
		std::cout << "0) quit" << std::endl;
		std::cout << "1) print all student names" << std::endl;
		std::cout << "2) print all student data" << std::endl;
		std::cout << "3) find a student" << std::endl << std::endl;
		std::cout << "please choose 0-3: ";
		std::cin >> choice;
		if (choice == "0") {
			keepGoing = false;
		} else if (choice == "1") {
			showStudentNames(students);
		} else if (choice == "2") {
			printStudents(students);
		} else if (choice == "3") {
			findStudent(students);
		} else {
			std::cout << "invalid input, please try again" << std::endl;
		} // end if
	} // end while
	delStudents(students);
} // end menu
