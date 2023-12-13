#include "Withdraw.h"
#include <iostream>
#include <fstream>
#include <string>
#include "sfml.h"
using namespace std;


Withdraw::Withdraw()
{

	firstName = ' ';
	lastName = ' ';
	DepartmentName = ' ';
	regDate = ' ';
	gender = 'a';
	contactNo, BloodGroup, Address;
	bool feeStatus = false;
	int marks = 0;
	string sID;
	int count = 0;

	string loggedIn;
}

bool Withdraw::Login()
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

	}
	if (id != sID)
	{
		playSound();
		cout << endl << "No Student Exists!" << endl;
		return 0;
	}

	infile.close();

	return 0;
}

int Withdraw::Menu()
{

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            ADMIN MENU              " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " Enrolled Courses                (1)" << endl;
	cout << " Drop a Course                   (2)" << endl;
	cout << " Exit                            (3)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 4)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	system("pause");

	return choice;
}

void Withdraw::viewCourses()
{
	system("cls");

	ifstream infile;
	infile.open("Registration.txt", ios::in);

	cout << "---------Courses---------" << endl;


	// Read and print each line from the file
	while (!infile.eof())
	{
		infile >> stuID >> courseName1 >> courseName2 >> courseName3 >> courseName4;
		if (stuID == loggedIn)
		{
			cout << "-------------------------" << endl;
			cout << courseName1 << endl << courseName2 << endl << courseName3 << endl
				<< courseName4 << endl;
		}
	}
	cout << "-----------------------" << endl;

	system("pause");

	infile.close();
}

void Withdraw::dropcourse()
{
	viewCourses(); // Display courses before allowing the user to drop a course

	string studentID = loggedIn;

	// Prompt the user to enter the course to be dropped
	string courseToDrop;
	cout << "Enter the course name to withdraw: ";
	cin >> courseToDrop;

	// Open the Registration file in read mode
	ifstream infile("Registration.txt", ios::in);

	// Open a temporary file to store modified data
	ofstream tempFile("TempRegistration.txt", ios::out);

	bool studentFound = false;

	while (!infile.eof()) {
		string tempStudentID, course1, course2, course3, course4;

		infile >> tempStudentID >> course1 >> course2 >> course3 >> course4;

		if (tempStudentID == studentID) {
			studentFound = true;
			// Check if the course to drop matches any of the registered courses
			if (course1 == courseToDrop) {
				tempFile << tempStudentID  << " " << course2 << " " << course3 << " " << course4 << endl;
			}
			else if (course2 == courseToDrop) {
				tempFile << tempStudentID << " " << course1 << course3 << " " << course4 << endl;
			}
			else if (course3 == courseToDrop) {
				tempFile << tempStudentID << " " << course1 << " " << course2 <<  course4 << endl;
			}
			else if (course4 == courseToDrop) {
				tempFile << tempStudentID << " " << course1 << " " << course2 << " " << course3 <<  endl;
			}
			else {
				// If the course does not match, keep the original line
				tempFile << tempStudentID << " " << course1 << " " << course2 << " " << course3 << " " << course4 << endl;
			}
		}
		else {
			// If the student does not match, keep the original line
			tempFile << tempStudentID << " " << course1 << " " << course2 << " " << course3 << " " << course4 << endl;
		}
	}

	infile.close();
	tempFile.close();

	if (!studentFound) {
		playSound();
		cout << "Student not found for withdrawal." << endl;
		remove("TempRegistration.txt"); // Remove the temporary file
	}
	else {
		// Remove the original Registration file
		remove("Registration.txt");

		// Rename the temporary file to the original Registration file
		rename("TempRegistration.txt", "Registration.txt");
		cout << "Course " << courseToDrop << " withdrawn successfully!" << endl;
	}

	system("pause");
}

Withdraw::~Withdraw() {}