//Teacher.h
// registration.h
#pragma once
#ifndef Registration_H
#define Registration_H

#include "Coder.h"
#include <string>
using namespace std;

class Registration : public coder
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

	Registration();

	//friend istream& operator >> (istream& in, Registration& obj);

	bool Login();
	int Menu();

	void viewCourses();
	void Availablecourse();
	void Registercourse();


	~Registration();
};

#endif