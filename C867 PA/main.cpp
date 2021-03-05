//WGU C867 PA
//Nikolas Butalid

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	const string studentData[] =
		{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5, Nikolas,Butalid,nbutali@wgu.edu,24,7,7,7,SOFTWARE" };

	Roster classRoster(studentData);


	
	classRoster.printAll();

	//Testing data parsing
	/*
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
		int courseDays[3] = { courseDays1, courseDays2, courseDays3 };
		Student TestStud(id, firstName, lastName, email, age, courseDays, degree);
		TestStud.print();
		cout << endl;
	}
	*/

		
	//Unit testing Student class
	/*string id = "A2";
	string fName = "Nik";
	string lName = "Butalid";
	string email = "butalidnik@yahoo.com";
	int age = 24;
	//int courses[NUM_COURSES] = { 24, 32, 23 };

	DegreeProgram myDegree = DegreeProgram::NETWORK;
	int days[NUM_COURSES] = { 4, 2, 25 };

	Student Bob(id, fName, lName, email, age, days, myDegree);
	Bob.print(); */
	

	return 0;
}