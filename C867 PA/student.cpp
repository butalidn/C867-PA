#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//Construtor intializes object and loads given parameters into private data members
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->numDays = numDays;
	this->degree = degree;
}

//Mutator functions for ID, first and last name, email, age, days in courses, and degree
void Student::setID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDays(int* numDays) {
	this->numDays = numDays;
}

void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

//Prints all of student info except for email address
void Student::print() {
	//Ex: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
	cout << "Student ID: " << getID() << "\t ";
	cout << "First Name: " << getFirstName() << "\t ";
	cout << "Last Name: " << getLastName() << "\t ";
	
	//cout << "Email: " << getEmail() << "\t ";			//Email not asked for in requirements
	cout << "Age: " << getAge() << "\t ";
	cout << "daysInCourse: ";
	cout << "{";
	for (size_t i = 0; i < NUM_COURSES; ++i) {
		if (i == (NUM_COURSES - 1)) {
			cout << getDays()[i] << "} \t";
		}
		else {
			cout << getDays()[i] << ", ";
		}
	}
	cout << "Degree Program: ";

	switch (getDegree())
	{
	case DegreeProgram::NETWORK:
		cout << "NETWORK";
		break;
	case DegreeProgram::SECURITY:
		cout << "SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		cout <<  "SOFTWARE";
		break;
	}
	cout << endl;
	
}

//Access functions for ID, first and last name, email, age, days in courses, and degree
string Student::getID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int* Student::getDays() {
  	return numDays;
}

DegreeProgram Student::getDegree() {
	return degree;
}

//Destructor deletes the int pointer array that was created in roster.cpp
Student::~Student() {
	delete[] numDays;
}




