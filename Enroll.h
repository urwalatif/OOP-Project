#pragma once
#ifndef Enroll_H
#define Enroll_H

#include "Coder.h"
#include <string>
using namespace std;

class Enroll : public coder
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

	Enroll();

	//friend istream& operator >> (istream& in, Enroll& obj);

	bool Login();
	int Menu();
	void AddData();
	void viewAllStudents();
	void removeStudent();
	void editStudent();
	void countLines();
	//void DisplayRollNo();

	~Enroll();
};

#endif