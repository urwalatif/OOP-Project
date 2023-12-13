#pragma once
#ifndef Marks_H
#define Marks_H

#include "Coder.h"
#include <string>
using namespace std;

class Marks : public coder
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

	Marks();

	//friend istream& operator >> (istream& in, Marks& obj);

	bool Login();
	int Menu();
	void viewMarks();
	void AssignMarks();

	~Marks();
};

#endif