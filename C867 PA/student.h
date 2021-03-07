#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

const int NUM_COURSES = 3;

class Student {
	public:
		Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, DegreeProgram degree);
		void setID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDays(int* numDays);
		void setDegree(DegreeProgram degree);
		void print();
		string getID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDays();
		DegreeProgram getDegree();
		~Student();
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int* numDays;
		DegreeProgram degree;
};

#endif