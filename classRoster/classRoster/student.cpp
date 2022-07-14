#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;

///////////////////////////////////////
////Constructors for Student Object////
///////////////////////////////////////

Student::Student() {
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int x = 0; x < daysToCompletionSize; x++) {
		this->daysToCompletion[x] = 0;
	}
}

Student::Student(string studentID, string fName, string lName, string emailAddress, int age, int daysToCompletion[], DegreeProgram degree) {
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int x = 0; x < daysToCompletionSize; x++) {
		this->daysToCompletion[x] = daysToCompletion[x];
	}
	this->degree = degree;
}


///////////////////////////////////////
//Accessors for each of the variables//
///////////////////////////////////////

string Student::getStudentID() const {
	return studentID;
}

string Student::getFName() const {
	return fName;
}

string Student::getLName() const {
	return lName;
}

string Student::getEmailAddress() const {
	return emailAddress;
}

int Student::getAge() const {
	return age;
}

int * Student::getDaysToCompletion() {
	return daysToCompletion;
}

string Student::getDegree() const {
	return degreeProgramStrings[degree];
}

///////////////////////////////////////
//Mutators for each of the variables///
///////////////////////////////////////

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFName(string firstName) {
	fName = firstName;
}

void Student::setLName(string lastName) {
	lName = lastName;
}

void Student::setEmailAddress(string email) {
	emailAddress = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompletion(int daysToCompletion[]) {
	for (int x = 0; x < daysToCompletionSize; x++) {
		this->daysToCompletion[x] = daysToCompletion[x];
	}
}

void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

///////////////////////////////////////
////Print method for all variables/////
///////////////////////////////////////

void Student::print() {
	cout << "Student ID: " << studentID << "\t";
	cout << "First Name: " << fName << "\t";
	cout << "Last Name: " << lName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t";
	cout << "Days In Course: ";
	for (int x = 0; x < daysToCompletionSize; x++) {
		cout << daysToCompletion[x] << "\t";
	}
	cout << "Degree Program: " << degreeProgramStrings[degree] << endl;
	cout << endl;
}

///////////////////////////////////////
////////Destructor for Student/////////
///////////////////////////////////////

Student::~Student() {}
