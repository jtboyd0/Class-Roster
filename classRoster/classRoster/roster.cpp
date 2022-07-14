#include "roster.h"
using std::cout;
using std::endl;
using std::cerr;

//Empty Constructor for Roster
Roster::Roster() {
	this->maxSize = 0;
	this->lIndex = -1;
	this->classRosterArray = nullptr;
}

//Constuctor for Roster, Inputs maxSize variable
Roster::Roster(int maxSize) {
	this->maxSize = maxSize;
	this->lIndex = -1;
	this->classRosterArray = new Student * [maxSize];
}

//Parses the data from studentData string and adds it to a student object
void Roster::parse(string studentData) {
	if (lIndex < maxSize) {
		lIndex++;
		
		int comma = studentData.find(",");
		string ID = studentData.substr(0, comma);
		comma++;

		int nextComma = studentData.find(",", comma);
		string fName = studentData.substr(comma, nextComma - comma);

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		string lName = studentData.substr(comma, nextComma - comma);

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		string email = studentData.substr(comma, nextComma - comma);

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		int age = stoi(studentData.substr(comma, nextComma - comma));

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		int day1 = stoi(studentData.substr(comma, nextComma - comma));

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		int day2 = stoi(studentData.substr(comma, nextComma - comma));

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		int day3 = stoi(studentData.substr(comma, nextComma - comma));

		comma = nextComma;
		comma++;
		nextComma = studentData.find(",", comma);
		string degree = studentData.substr(comma, studentData.size() - comma);

		DegreeProgram studentDegree = NETWORK;
		if (degree == "SECURITY") {
			studentDegree = SECURITY;
		}
		else if (degree == "NETWORK") {
			studentDegree = NETWORK;
		}
		else if (degree == "SOFTWARE") {
			studentDegree = SOFTWARE;
		}

		add(ID, fName, lName, email, age, day1, day2, day3, studentDegree);
	}
	else {
		cerr << "ERROR: LIST HAS EXCEEDED MAX SIZE";
		exit(-1);
	}
}

//Given the input needed for the student constructor, a student object is created and added to the classRoster Array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysToCompletion[Student::daysToCompletionSize];
	daysToCompletion[0] = daysInCourse1;
	daysToCompletion[1] = daysInCourse2;
	daysToCompletion[2] = daysInCourse3;
	classRosterArray[lIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompletion, degreeprogram);
}

//Prints all of the students in the classRosterArray utilizing the student classes print method
void Roster::printAll() {
	cout << "Printing Roster: " << endl;
	for (int x = 0; x <= lIndex; x++) {
		classRosterArray[x]->print();
	}

	cout << "Complete.\n" << endl;
}

//Removes a student object from the class roster array and moves the last student in the array into the removed student's position. 
void Roster::remove(string studentID) {
	cout << "Attempting to remove student: " << studentID << endl;
	for (int x = 0; x <= lIndex; x++) {
		if (classRosterArray[x]->getStudentID() == studentID){
			delete classRosterArray[x];
			classRosterArray[x] = classRosterArray[lIndex];
			lIndex--;
			cout << "Removed.\n" << endl;
			return;
		}
	}
	cout << "STUDENT ID NOT FOUND.\n" << endl;
}

//This method finds a given student ID and prints the average days in the 3 classes.
void Roster::printAverageDaysInCourse(string studentID) {
	for (int x = 0; x <= lIndex; x++) {
		if (this->classRosterArray[x]->getStudentID() == studentID) {
			int* pointer = classRosterArray[x]->getDaysToCompletion();
			cout << "Average # of days for Student " << studentID << ": " << (pointer[0] + pointer[1] + pointer[2]) / 3 << "\n";
			return;
		}
	}
	cout << "Student ID Not Found" << endl;
}

//Checks to see if an email is invalid, if the email is invalid it will print it.
//A valid email contains an "@" symbol and a "." symbol. The email is also invalid if it contains any spaces.
void Roster::printInvalidEmails(){
	cout << "Printing Invalid Emails:" << endl;
	for (int x = 0; x <= lIndex; x++) {
		string email = classRosterArray[x]->getEmailAddress();
		if (email.find(" ") < email.size() && email.find(" ") >= 0) {
			cout << email << endl;
		}
		else if (email.find("@") > email.size() || email.find("@") < 0) {
			cout << email << endl;
		}
		else if (email.find(".") > email.size() || email.find(".") < 0) {
			cout << email << endl;
		}
	}
	cout << endl;
}

//Prints all students in the roster that are in a specified degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Printing Students in degree program " << degreeProgramStrings[degreeProgram] << ":" << endl;
	string degree = degreeProgramStrings[degreeProgram];
	for (int x = 0; x <= lIndex; x++) {
		if (classRosterArray[x]->getDegree() == degree) {
			classRosterArray[x]->print();
		}
	}
}

//Accesses a student object in the roster
Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

//Empties all of the students in the Roster Array
Roster::~Roster() {
	for (int x = 0; x < lIndex; x++) {
		delete this->classRosterArray[x];
	}
}

