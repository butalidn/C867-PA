#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include "student.h"
using namespace std;

class Roster {
public:
	Roster(const string* studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
private:
	Student* classRosterArray[5];
	int numStudents = 0;
	int* courseDays;
};
#endif //
