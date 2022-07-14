#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
public:

	const static int daysToCompletionSize = 3;

protected:

	string studentID;
	string fName;
	string lName;
	string emailAddress;
	int age;
	int daysToCompletion[daysToCompletionSize];
	DegreeProgram degree;

public:

	///////////////////////////////////////////////
	//Accessors for each of the private variables//
	///////////////////////////////////////////////

	string getStudentID() const; //Gets the ID of a student
	string getFName() const; //Gets the first name of a student
	string getLName() const; //Gets the last name of a student
	string getEmailAddress() const; //Gets the email address of a student
	int getAge() const; //Gets the age of a student
	int* getDaysToCompletion(); //Gets the array of the days to completion for 3 classes for a student
	string getDegree() const; //Gets the degree program a student is in

	///////////////////////////////////////
	//Mutators for each of the variables///
	///////////////////////////////////////

	void setStudentID(string studentID); //Sets the StudentID for a student object
	void setFName(string firstName); //Sets the First Name for a student object
	void setLName(string lastName); //Sets the last name for a student object
	void setEmailAddress(string email); //sets the email address for a student object
	void setAge(int age); //Sets the age for a student object
	void setDaysToCompletion(int daysToCompletion[]); //Sets the array of days for a student object
	void setDegree(DegreeProgram degree); //Sets the degree program for a student object

	///////////////////////////////////////////////
	////////Constructors for student object////////
	///////////////////////////////////////////////

	Student();
	Student(string conStudentID, string conFName, string conLName, string conEmailAddress, int conAge, int conDaysToCompletion[],DegreeProgram degree);


	///////////////////////////////////////
	////Print method for all variables/////
	///////////////////////////////////////

	void print();

	///////////////////////////////////////
	////////Destructor for Student/////////
	///////////////////////////////////////

	~Student();
};
