//Enroll.cpp
#include "Enroll.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


Enroll::Enroll()
{
	firstName = lastName = DepartmentName = regDate = ".";
	gender = '.';
	contactNo = ".";
	BloodGroup = Address = ".";
	feeStatus = 0;
	marks = 0;
}

bool Enroll::Login()
{

	string id, pass;

	system("cls");
	cout << " --------------------------------------- " << endl;
	cout << "               TEACHER LOGIN             " << endl;
	cout << " --------------------------------------- " << endl << endl;
	cout << "    ID (Hina)          :"; cin >> id;
	cout << "    PASSWORD (OOP123)    :"; cin >> pass;
	cout << " --------------------------------------- " << endl;

	
	if (id == "Hina" && pass == "OOP123")
	{
		cout << endl << "Login Success!" << endl;
		return 1;
	}
	else 
	{
		cout << endl << "No Teacher Exists! " << endl;
		return 0;
	}

}

int Enroll::Menu()
{

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            STUDENT MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << "Enrolled Students                (1)" << endl;
	cout << "Add a Student                    (2)" << endl;
	cout << "Remove a Student                 (3)" << endl;
	cout << "Edit a Student                   (4)" << endl;
	cout << "Exit                             (5)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	while (!(choice > 0 && choice < 6))
	{
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//display all students.
void Enroll::viewAllStudents()
{

	system("cls");

	ifstream infile;
	infile.open("Enroll.txt", ios::in);

	cout << "________________________________________Students_______________________________________________________" << endl;
	cout << " _____________________________________________________________________________________________________ " << endl;
	cout << "|  ID      FirstName   LastName   Gender   Department     Contact             Address        FeeStatus |" << endl;
	cout << "| ____________________________________________________________________________________________________ |" << endl;

	bool a = 1;
	while (a==1)
	{
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		if (!infile.eof())
		{
			cout << "| " << setw(5) << sID << setw(12) << firstName << setw(10) << lastName << setw(6) << gender << setw(10) << DepartmentName << setw(24) << contactNo << setw(15) << Address<<setw(10)<<feeStatus << "  |" << endl;
		}
		else
		{
			a = 0;
			break;
		}
	}

	cout << " _____________________________________________________________________________________ " << endl;
	system("pause");
	infile.close();
}

//save data to file.
void Enroll::AddData()
{
	system("cls");
	
	cout << " ------------------------------------------------- " << endl;
	cout << "               Enter New Student Data              " << endl;
	cout << " ------------------------------------------------- " << endl;
	cout << "Enter First Name             : "; cin >> firstName;
	cout << "Enter Last Name              : "; cin >> lastName;
	cout << "Enter Student ID             : "; cin >> sID;
	cout << "Enter Department Name        : "; cin >> DepartmentName;
	cout << "Enter Registration Date      : "; cin >> regDate;
	cout << "Enter Gender                 : "; cin >> gender;
	cout << "Enter Contact No.            : "; cin >> contactNo;
	cout << "Enter Address                : "; cin >> Address;
	cout << "Enter Fee Status             : "; cin >> feeStatus;
	cout << "Enter Blood Group            : "; cin >> BloodGroup;
	cout << " ------------------------------------------------- " << endl;

	ofstream outfile;
	outfile.open("Enroll.txt", ios::app);

	// Save new student data to the file
	outfile <<endl<< firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
		<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup ;

	outfile.close();


	system("pause");
}

void Enroll::removeStudent()
{
	system("cls");
	//DisplayRollNo();

	string checkID;
	cout << "Enter Student ID to Remove: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;
	infile.open("Enroll.txt", ios::in);

	ofstream outfile;
	outfile.open("NewStudent.txt", ios::app);

	if (!infile) {
		cout << "File does not exist! ";
	}
	else {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

		while (!infile.eof()) {
			if (checkID == sID) {
				// Skip the record to be removed
				infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
				continue;
			}

			// Save data to the new file
			outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
				<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;

			// Getting data for the next student
			infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		}
	}

	infile.close();
	outfile.close();

	remove("Enroll.txt");
	rename("NewStudent.txt", "Enroll.txt");

}

//edit specific student.
void Enroll::editStudent()
{

	system("cls");
	//DisplayRollNo();

	string checkID;
	cout << "Enter Student ID to Edit: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;
	infile.open("Enroll.txt", ios::in);

	ofstream outfile;
	outfile.open("NewStudent.txt", ios::app);

	if (!infile)
	{
		cout << "File does not exist! ";
	}
	else
	{
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

		while (!infile.eof())
		{

			if (checkID == sID)
			{ //If ID match then edit and save data.
				cout << " ------------------------------------------------- " << endl;
				cout << "                   Enter New Data                  " << endl;
				cout << " ------------------------------------------------- " << endl;
				cout << "Enter First Name             : "; cin >> firstName;
				cout << "Enter Last Name              : "; cin >> lastName;
				cout << "Enter Fee Status             : "; cin >> feeStatus;
				cout << "Enter Address                : "; cin >> Address;
				cout << "Enter Contact No.            : "; cin >> contactNo;
				cout << "Enter Blood Group            : "; cin >> BloodGroup;
				cout << " ------------------------------------------------ " << endl;

				system("pause");

				outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
					<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
			}
			else
			{ //If ID not match then save data as it is.
				outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
					<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
			}
			//getting data for next teacher.
			infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		}
	}

	infile.close();
	outfile.close();

	remove("Enroll.txt");
	rename("NewStudent.txt", "Enroll.txt");
}

////count number of lines in file and hence number of students.
void Enroll::countLines()
{

	ifstream countfile;
	count = -1;
	countfile.open("Student.txt", ios::in);

	while (!countfile.eof())
	{

		countfile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		count++;
	}
	countfile.close();
}



Enroll::~Enroll()
{

}