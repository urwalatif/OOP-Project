//Marks.cpp
#include "Marks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "sfml.h"

using namespace std;



Marks::Marks()
{
	firstName = lastName = DepartmentName = regDate = ".";
	gender = '.';
	contactNo = ".";
	BloodGroup = Address = ".";
	feeStatus = 0;
	marks = 0;
}

bool Marks::Login()
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

int Marks::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            STUDENT MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View Marks                      (1)" << endl;
	cout << " Assign MArks                    (2)" << endl;
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
void Marks::AssignMarks() {

	system("cls");

	string studentID = loggedIn;

	// Display subjects for the student
	ifstream registrationFile;
	registrationFile.open("Registration.txt", ios::in);

	cout << "Subjects available for assigning marks:" << endl;

	while (!registrationFile.eof()) {
		string tempStudentID, subject1, subject2, subject3, subject4;

		registrationFile >> tempStudentID >> subject1 >> subject2 >> subject3 >> subject4;

		if (tempStudentID == studentID) {
			cout << subject1 << endl << subject2 << endl << subject3 << endl << subject4 << endl;
			system("pause");
			break;  // No need to continue reading the file once the student is found
		}
	}

	registrationFile.close();

	// Get the subject for which you want to assign marks
	string selectedSubject;
	cout << "Enter the subject for which you want to Assign Marks: ";
	cin >> selectedSubject;

	// Get the marks for the selected subject
	int marks;
	cout << "Enter the marks for the selected subject: ";
	cin >> marks;

	// Open the Marks file in append mode
	ofstream marksFile;
	marksFile.open("Marks.txt", ios::app);

	// Write the marks record to the file
	marksFile <<endl<< studentID << "\t" << selectedSubject << "\t" << marks ;

	cout << "Marks assigned successfully for subject " << selectedSubject << "!" << endl;

	marksFile.close();

	system("pause");
}

void Marks::viewMarks()
{

	system("cls");

	// Assuming you already have the student ID stored in loggedIn
	string studentID = loggedIn;

	ifstream marksFile;
	marksFile.open("Marks.txt", ios::in);

	cout << "Marks for Student ID: " << studentID << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Stu-ID\tSubject\t\tMarks" << endl;

	while (!marksFile.eof()) {
		string tempStudentID, subject;
		int marks;

		marksFile >> tempStudentID >> subject >> marks;

		if (tempStudentID == studentID) {
			cout << tempStudentID << "\t" << subject  << "\t\t" << marks << endl;
		}
	}

	marksFile.close();

	cout << "----------------------------------------------" << endl;
	system("pause");


}



Marks::~Marks()
{

}

