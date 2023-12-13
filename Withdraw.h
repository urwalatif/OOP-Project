#pragma once
#ifndef Withdraw_H
#define Withdraw_H

#include "Coder.h"
#include <string>
using namespace std;

class Withdraw : public coder
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
	Withdraw();
	bool Login();
	int Menu();

	void viewCourses();
	void dropcourse();


	~Withdraw();
};

#endif