# Algorithm for Heap of Students program
## Mermaid diagram
```mermaid
classDiagram
    class Address {
        - string street
        - string city
        - string state
        - string zip
        + Address()
        + ~Address()
        + void init(string street, string city, string state, string zip)
        + void printAddress()
    }
    class Date {
        - string date
        - int day
        - int month
        - int year
        + Date()
        + ~Date()
        + void init(string date)
        + string monthToString()
        + void printDate()
    }
    class Student {
        - Address* studentAddress
        - Date* birthDate
        - Date* gradDate
        - string firstName
        - string lastName
        - int creditHours
        + Student()
        + ~Student()
        + void init(string Studentstring)
        + void printStudent()
        + string getLastFirst()
    }
    Student o-- Address
    Student o-- Date
```
## Algorithm for main
### Algorithm for loadStudents
0. parameter: students vector (reference)
1. create filestream inFile for students.csv
1. string currentLine;
1. open inFile
1. bool keepGoing = true;
1. while(keepGoing)
    1. if (inFile.eof())
        1. keepGoing = false;
    1. else
        1. getLine(inFile, currentLine)
        1. Student student = new Student();
        1. student.init(currentLine);
        1. append student to vector
    1. end if
1. end while
1. close inFile
### Algorithm for printStudents
0. parameter: students vector (reference)
1. for every student in students (using vector iterator, students.begin() and students.end())
    1. student.printStudent();
    1. print a new line
1. end for
### Algorithm for showStudentNames
0. parameter: students vector (reference)
1. for every student in students
    1. print student.getLastFirst() + student.getCredits() + new line
1. end for
### Algorithm for findStudent
0. parameter: students vector (reference)
1. string search = "";
1. print "last name of student: "
1. put user input into search
1. for every student in students
    1. int match = 0
    1. match = std::student.getLast().find(search)
    1. if (match != -1)
        1. student.printStudent();
    1. end if
1. end for
### Algorithm for delStudents
0. parameter: students vector (reference)
1. for every student in students
    1. delete student
1. end for
### Algorithm for menu
1. create students vector
1. loadStudents(students);
1. string choice = "";
1. bool keepGoing = true;
1. while (keepGoing)
    1. print "0) quit" + new line
    1. print "1) print all student names" + new line
    1. print "2) print all student data" + new line
    1. print "3) find a student" + new line + new line
    1. print "please choose 1-3:"
    1. put user input into choice
    1. if (choice == "0")
        1. keepGoing = false;
    1. else if (choice == "1")
        1. showStudentNames(students);
    1. else if (choice == "2")
        1. printStudents(students);
    1. else if (choice == "3")
        1. findStudent(students);
    1. else
        1. print "invalid input, please try again"
    1. end if
1. end while
1. delStudents(students);
## Algorithm for Address
### Header
1. protected:
    1. string street
    1. string city
    1. string state
    1. string zip
1. public:
    1. no-argument Address constructor
    1. Address deconstructor
    1. void init(string street, string city, string state, string zip)
    1. void printAddress()
### Implementation
1. Address constructor
    1. street = "";
    1. city = "";
    1. state = "";
    1. zip = "";
1. Address deconstructor
1. void init(string street, string city, string state, string zip)
    1. Address::street = street;
    1. Address::city = city;
    1. Address::state = state;
    1. Address::zip = zip;
1. void printAddress()
    1. print(street + \n + city + state + ", " + zip + \n);
## Algorithm for Date
### Header
1. protected:
    1. string date
    1. int day
    1. int month
    1. int year
1. public:
    1. no-argument Date constructor
    1. Date deconstructor
    1. void init(string date)
    1. string monthToString()
    1. void printDate()
## Implementation
1. Date constructor
    1. date = "";
    1. day = 0;
    1. month = 0;
    1. year = 0;
1. Date deconstructor
1. void init(string date)
    1. Date::date = date;
    1. put date into stringstream
    1. get first value (with "/" seperating value) and put it into month
    1. get next value and put it into day
    1. get last value and put it into year
1. string monthToString()
    1. string stringMonth = "";
    1. if (month = 1)
        1. stringMonth = "January";
    1. else if (month = 2)
        1. stringMonth = "February";
    1. else if (month = 3)
        1. stringMonth = "March";
    1. else if (month = 4)
        1. stringMonth = "April";
    1. else if (month = 5)
        1. stringMonth = "May";
    1. else if (month = 6)
        1. stringMonth = "June";
    1. else if (month = 7)
        1. stringMonth = "July";
    1. else if (month = 8)
        1. stringMonth = "August";
    1. else if (month = 9)
        1. stringMonth = "September";
    1. else if (month = 10)
        1. stringMonth = "October";
    1. else if (month = 11)
        1. stringMonth = "November";
    1. else
        1. stringMonth = "December";
    1. end if
    1. return stringMonth;
1. void printDate()
    1. print(monthToString() + day + ", " + year + \n);
## Algorithm for Student
### Header
1. protected:
    1. Address* studentAddress;
    1. Date* birthDate;
    1. Date* gradDate;
    1. string firstName;
    1. string lastName;
    1. int creditHours;
1. public:
    1. no-argument Student constructor
    1. Student deconstructor
    1. void init(string studentString)
    1. void printStudent();
    1. string getLastFirst();
    1. int getCredits();
### Implementation
1. Student constructor
    1. studentAddress = new Address();
    1. birthDate = new Date();
    1. gradDate = new Date();
    1. firstName = "";
    1. lastName = "";
    1. creditHours = 0;
1. Student deconstructor
    1. delete studentAddress;
    1. delete birthDate;
    1. delete gradDate;
1. void init(string studentString)
    1. put studentString into stringstream
    1. put first value into firstName
    1. put second value into lastName
    1. initialize studentAddress and pass next four values in as parameters
    1. initialize birthDate and pass next value in as a parameter
    1. initialize gradDate and pass next value in as a parameter
    1. put remaining value into creditHours
1. void printStudent()
    1. print firstName and lastName
    1. print studentAddress
    1. print "DOB:" and birthDate
    1. print "grad: " and gradDate
    1. print "credits: " and creditHours
    1. print "_ " 36 times to act as a divider
1. string getLastFirst()
    1. pass lastName into stringstream
    1. pass ", " into stringstream
    1. pass firstName into stringstream
    1. return the stringstream as a string
1. int getCredits()
    1. return creditHours;

