//Registration.cpp
#include "Registration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "sfml.h"

using namespace std;

Registration::Registration()
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

bool Registration::Login()
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

int Registration::Menu()
{

	int choice;

	system("cls");
	cout << "-------------------------------------------" << endl;
	cout << "              Register Course              " << endl;
	cout << "-------------------------------------------" << endl << endl;
	cout << "                                      Press" << endl << endl;
	cout << "View All Registered Courses             (1)" << endl;
	cout << "Avialable Courses                       (2)" << endl;
	cout << "Register Course                         (3)" << endl;
	cout << "Exit                                    (4)" << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl;

	cout << "Enter your choice: ";
	cin >> choice;

	while (!(choice > 0 && choice < 5))
	{
		playSound();
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	system("pause");
	return choice;
}

void Registration::viewCourses()
{
	system("cls");

	ifstream infile;
	infile.open("Registration.txt", ios::in);

	cout << "---------Courses---------" << endl;


	// Read and print each line from the file
	while (!infile.eof())
	{
		infile >> stuID >> courseName1 >> courseName2 >> courseName3>> courseName4;
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
void Registration::Availablecourse()
{
	system("cls");

	// Display available courses
	cout << "___________________________________________" << endl;
	cout << endl;
	cout << "\tCourses in Which you can Register" << endl;
	cout << endl;
	cout << "___________________________________________" << endl;

	ifstream availableCoursesFile;
	availableCoursesFile.open("AvailableCourses.txt", ios::in);

	while (!availableCoursesFile.eof())
	{
		string course;
		getline(availableCoursesFile, course);
		cout << course << endl;
	}

	cout << endl;
	cout << "___________________________________________" << endl;
	availableCoursesFile.close();

	system("pause");
}
void Registration::Registercourse()
{
	  system("cls");

    // Display available courses
	cout << "___________________________________________" << endl;
	cout << endl;
    cout << "\tCourses in Which you can Register" << endl;
	cout << endl;
	cout << "___________________________________________" << endl;

    ifstream availableCoursesFile;
    availableCoursesFile.open("AvailableCourses.txt", ios::in);

    while (!availableCoursesFile.eof())
    {
        string course;
        getline(availableCoursesFile, course);
        cout << course << endl;
    }

	cout << endl;
	cout << "___________________________________________" << endl;
    availableCoursesFile.close();

	cout << endl;
    // Get the course name from the user
    string selectedCourse;
    cout << "Enter the course you want to register: ";
    cin >> selectedCourse;

	cout << endl;
	cout << "___________________________________________" << endl;
	cout << endl;
	system("pause");

    // Check if the selected course is available
    ifstream availableCoursesCheckFile;
    availableCoursesCheckFile.open("AvailableCourses.txt", ios::in);

    bool courseAvailable = false;

    while (!availableCoursesCheckFile.eof())
    {
        string course;
        getline(availableCoursesCheckFile, course);
        if (course == selectedCourse)
        {
            courseAvailable = true;
            break;
        }
    }

    availableCoursesCheckFile.close();

    // Register the course if available
    if (courseAvailable)
    {
        ofstream registrationFile;
        registrationFile.open("Registration.txt", ios::app); // Open file in append mode

        // Assuming you already have the student ID stored in loggedIn
        registrationFile << loggedIn << " " << selectedCourse << endl;

        registrationFile.close();

        cout << "Course registration successful!" << endl;
    }
    else
    {
		playSound();
        cout << "Selected course is not available. Registration failed." << endl;
    }

    system("pause");
}

Registration::~Registration()
{

}