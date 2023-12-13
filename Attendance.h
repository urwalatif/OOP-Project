#pragma once
#pragma once
#ifndef Attendance_H
#define Attendance_H

#include "Coder.h"
#include <string>
using namespace std;

class Attendance : public coder
{
	string firstName, lastName, DepartmentName, regDate;
	char gender;
	string contactNo, BloodGroup, Address;
	bool feeStatus;
	int marks;
	string sID;
	int count;

	string loggedIn;

public:

	Attendance();

	//friend istream& operator >> (istream& in, Attendance& obj);

	bool Login();
	int Menu();
	void markAttendance();
	void viewAttendance();

	~Attendance();
};

#endif