#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"
#include <sstream>
#include <vector>
using namespace std;

//Takes in studentData string and parses information and calls the 'add' function for each student object
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

//Parses data using comma delimiter and string stream
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

//Takes in parameters and creates a Student object
//An array of int pointers are created that is later deleted in Student destructor
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int* courseDays = new int[NUM_COURSES];
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeprogram);
}

//Takes the given ID and sets all of the values of the Student object to a default value
void Roster::remove(string studentID) {
	bool foundID = false;
	while (!foundID) {
		for (int i = 0; i < numStudents; ++i) {
			if (classRosterArray[i]->getID().compare(studentID) == 0) {
				classRosterArray[i]->setID("");
				classRosterArray[i]->setFirstName("");
				classRosterArray[i]->setLastName("");
				classRosterArray[i]->setEmail("");
				classRosterArray[i]->setAge(0);
				classRosterArray[i]->getDays()[0] = 0;
				classRosterArray[i]->getDays()[1] = 0;
				classRosterArray[i]->getDays()[2] = 0;
				classRosterArray[i]->setDegree(DegreeProgram::NONE);
				foundID = true;
				return;
			}
		}
		cout << "ERROR- Student could not be found by given ID (\"" << studentID << "\")" << endl;
		break;
	}
}

//Only prints out valid Student objects
void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i)
	{
		if (classRosterArray[i]->getID().compare("") != 0)
		{
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}

//Takes the array of days and find the mean value
void Roster::printAverageDaysInCourse(string studentID) {
	double totalDays = 0;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getID().compare(studentID) == 0) {
			for (int j = 0; j < NUM_COURSES; ++j) {
				totalDays = classRosterArray[i]->getDays()[j] + totalDays;
			}
		}
	}
	cout << "(Student ID: " << studentID << ") Average Days in Course: " << (totalDays / 3) << " days" << endl << endl;
}

//Checks if email contains a space, or missing a '@' or a '.'
void Roster::printInvalidEmails() {
	bool allValid = true;
	size_t position = 0;
	cout << "Checking for invalid emails..." << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getEmail().find(" ") != string::npos)
		{
			cout << "INVALID (contains a space): " << classRosterArray[i]->getEmail() << endl;
			allValid = false;
		}
		else if (classRosterArray[i]->getEmail().find('@') == string::npos)
		{
			cout << "INVALID (Missing \"@\"): " << classRosterArray[i]->getEmail() << endl;
			allValid = false;
		}
		else if (classRosterArray[i]->getEmail().find('.') == string::npos)
		{
			cout << "INVALID (Missing \".\"): " << classRosterArray[i]->getEmail() << endl;
			allValid = false;
		}
	}
	if (allValid) {
		cout << "All emails are valid!" << endl;
	}
	cout << endl;
}

//Prints student info by given degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degree = "";
	switch (degreeProgram)
	{
	case DegreeProgram::NETWORK:
		degree = "NETWORK";
		break;
	case DegreeProgram::SECURITY:
		degree = "SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		degree = "SOFTWARE";
		break;
	}
	cout << "Printing all " + degree + " students..." << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getDegree() == degreeProgram)
		{
			classRosterArray[i]->print();
			cout << endl << endl;

		}
	}
}

//Deletes the array of Student objects in classRosterArray
Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
	}
	return;
}