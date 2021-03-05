
#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"
#include <sstream>
#include <vector>
using namespace std;

Roster::Roster(const string* studentData) {
	string id = "";
	string firstName = "";
	string lastName = "";
	string email = "";
	int age = 0;
	int courseDays1 = 0;
	int courseDays2 = 0;
	int courseDays3 = 0;
	string degreeStr = "";
	DegreeProgram degree = DegreeProgram::NONE;

	//Testing the string pointer
	/*cout << "THIS IS TESTING ROSTER STRING DATA" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << studentData[i] << endl;
	}*/
	
	/*int bob[3] = { 1, 5,8 };
	classRosterArray[0] = new Student("A5", "Nik", "Butalid", "nbutali@wgu.edu", 24, bob, DegreeProgram::SOFTWARE);
	classRosterArray[0]->print();*/
	

	for (int i = 0; i < 5; ++i) {
		string studentStr = studentData[i];
		vector<string> data;
		stringstream str_stream(studentStr);
		while (str_stream.good()) {
			string substr;
			getline(str_stream, substr, ',');
			data.push_back(substr);
		}
		for (size_t j = 0; j < data.size(); ++j) {
			switch (j)
			{
			case 0:
				id = data.at(j);
				break;
			case 1:
				firstName = data.at(j);
				break;
			case 2:
				lastName = data.at(j);
				break;
			case 3:
				email = data.at(j);
				break;
			case 4:
				age = stoi(data.at(j));
				break;
			case 5:
				courseDays1 = stoi(data.at(j));
				break;
			case 6:
				courseDays2 = stoi(data.at(j));
				break;
			case 7:
				courseDays3 = stoi(data.at(j));
				break;
			case 8:
				degreeStr = data.at(j);
				if (degreeStr.compare("NETWORK") == 0) {
					degree = DegreeProgram::NETWORK;
				}
				else if (degreeStr.compare("SECURITY") == 0) {
					degree = DegreeProgram::SECURITY;
				}
				else if (degreeStr.compare("SOFTWARE") == 0) {
					degree = DegreeProgram::SOFTWARE;
				}
			}
		}
		add(id, firstName, lastName, email, age, courseDays1, courseDays2, courseDays3, degree);
		numStudents = numStudents + 1;
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int courseDays[NUM_COURSES] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeprogram);
}

/*void remove(string studentID) {
}*/

void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i)
	{
		classRosterArray[i]->print();
		cout << endl;
	}
}
/*
void printAverageDaysInCourse(string studentID) {

}

void printInvalidEmails() {

}

void printByDegreeProgram(DegreeProgram degreeProgram) {

}
*/
Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
	}
	
	return;
}