#pragma once
#include <iostream>
#include <string>
#include "student.h"

class Roster {
public:
	Roster();//Empty Constructor for roster
	Roster(int maxSize);//Constructor for roster, inputs a maximum size given in the main function

	Student* getStudentAt(int Index);//Accesses a student at a given index
	void parse(string studentData);//Parses the student data and adds it to a student object
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);//Adds the needed data for a student object into a student object and the student object into the roster array
	void remove(string studentID);//Removes a student object with a given ID
	void printAll();//Prints the class roster
	void printAverageDaysInCourse(string studentID);//Prints the average days in a course for a student with a given ID
	void printInvalidEmails();//Prints all emails in the roster that are invalid
	void printByDegreeProgram(DegreeProgram degreeProgram);//Prints every student in the roster in a specific degree program.

	~Roster();//Clears the data in the class roster

private:
	Student** classRosterArray;
	int lIndex;
	int maxSize;
};