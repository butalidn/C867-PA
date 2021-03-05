#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < NUM_COURSES; ++i) {
		this->numDays[i] = numDays[i];
	}
	this->numDays = numDays;
	this->degree = degree;
}

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

void Student::print() {
	
	cout << "Student ID: " << getID() << endl;
	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Age: " << getAge() << endl;

	cout << "Days to complete three courses: ";
	for (size_t i = 0; i < NUM_COURSES; ++i) {
		cout << this->getDays()[i] << " ";
	}

	cout << endl;
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



