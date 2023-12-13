//Attendance.cpp
#include "Attendance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "sfml.h"

using namespace std;



Attendance::Attendance()
{
	firstName = lastName = DepartmentName = regDate = ".";
	gender = '.';
	contactNo = ".";
	BloodGroup = Address = ".";
	feeStatus = 0;
	marks = 0;
}

bool Attendance::Login()
{

	string id;

	ifstream infile;
	infile.open("Enroll.txt", ios::in);

	system("cls");
	cout << " --------------------------------------- " << endl;
	cout << "               STUDENT LOGIN             " << endl;
	cout << " --------------------------------------- " << endl << endl;
	cout << "    ID           :"; cin >> id;
	cout << " --------------------------------------- " << endl;

	infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

	while (!infile.eof())
	{

		if (id == sID)
		{
			loggedIn = id;
			cout << endl << "Login Success!" << endl;
			return 1;
			break;
		}

		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

	};
	if (id != sID)
	{
		playSound();
		cout << endl << "No Student Exists!" << endl;
		return 0;
	}

	infile.close();

	return 0;
}

int Attendance::Menu()
{

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            STUDENT MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View Attendance                 (1)" << endl;
	cout << " Mark Attendance                 (2)" << endl;
	cout << " Exit                            (3)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 4))
	{
		playSound();
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//save data to file.

void Attendance::viewAttendance()
{
	system("cls");

	string studentID = loggedIn;

	ifstream attendanceFile;
	attendanceFile.open("Attendance.txt", ios::in);

	cout << "Attendance for Student ID: " << studentID << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Stu-ID\tSubject\t\tDate\t\tAttendance" << endl;

	while (!attendanceFile.eof()) {
		string tempStudentID, subject, date;
		char attendance;

		attendanceFile >> tempStudentID >> subject >> date >> attendance;

		if (tempStudentID == studentID) {
			cout << tempStudentID << "\t" << subject << "\t\t" << date << "\t\t" << attendance << endl;
		}
	}

	attendanceFile.close();

	cout << "----------------------------------------------" << endl;
	system("pause");
}

void Attendance::markAttendance()
{
	system("cls");

	string studentID = loggedIn;

	// Get the current date
	string currentDate;
	cout << "Enter the current date (format: DD/MM/YYYY) : ";
	cin >> currentDate;

	// Display subjects for the student
	ifstream registrationFile;
	registrationFile.open("Registration.txt", ios::in);

	cout << "Subjects available for marking attendance  : " << endl;

	while (!registrationFile.eof())
	{
		string tempStudentID, subject1, subject2, subject3, subject4;

		registrationFile >> tempStudentID >> subject1 >> subject2 >> subject3 >> subject4;

		if (tempStudentID == studentID)
		{
			cout << subject1 << endl << subject2 << endl << subject3 << endl << subject4 << endl;
			break;  // No need to continue reading the file once the student is found
		}
	}

	registrationFile.close();

	// Get the subject for which you want to mark attendance
	string selectedSubject;
	cout << "Enter the subject for which you want to mark attendance : ";
	cin >> selectedSubject;

	// Get the attendance status (Present or Absent)
	char attendanceStatus;
	cout << "Enter the attendance status (P for Present, A for Absent) : ";
	cin >> attendanceStatus;

	// Open the Attendance file in append mode
	ofstream attendanceFile;
	attendanceFile.open("Attendance.txt", ios::app);

	// Write the attendance record to the file
	attendanceFile << endl<<studentID << "\t" << selectedSubject << "\t\t" << currentDate << "\t\t" << attendanceStatus << endl;

	cout << "Attendance marked successfully for " << selectedSubject << "!" << endl;

	attendanceFile.close();

	system("pause");
}
Attendance::~Attendance()
{

}

