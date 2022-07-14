#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {
	
	int numStudents = 5;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jacob,Boyd ,jacob.boyd1@wgu.edu,21,50,58,40,SOFTWARE",
	};

	Roster* classRoster = new Roster(numStudents);
	for (int x = 0; x < numStudents; x++) {
		classRoster->parse(studentData[x]);
	}

	cout << "Scripting and Programming Applications C867" << endl;
	cout << "C++" << endl;
	cout << "#001393514" << endl;
	cout << "Jacob Boyd\n" << endl;

	classRoster->printAll();

	classRoster->printInvalidEmails();
	
	for (int x = 0; x < numStudents; x++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(x)->getStudentID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->printAll();
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	classRoster->~Roster();
	return 0;
}
