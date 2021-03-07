//WGU C867 PA
//Nikolas Butalid

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main()
{
	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS: C867" << endl;
	cout << "Using C++" << endl;
	cout << "WGU Student ID: 001531753" << endl;
	cout << "Nikolas Butalid" << endl << endl;

	const string studentData[] =
		{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nikolas,Butalid,nbutali@wgu.edu,24,5,7,22,SOFTWARE" };

	Roster classRoster(studentData);
	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	return 0;
}