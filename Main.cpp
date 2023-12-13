#include <iostream> //Main.cpp
#include <string>
#include <fstream>
#include <stdio.h>
#include "Enroll.h"
#include "Registration.h"
#include "Attendance.h"
#include "Marks.h"
#include "Withdraw.h"
#include "Coder.h"
#include "sfml.h"

int main()
{
	displayGraphic("Flex.jpg");//showing flex image(sfml)

	Enroll enroll;
	Registration reg;
	Attendance attend;
	Marks marks;
	Withdraw withdraw;

	int ctrl = 1, choice = 0, choice2 = 0;

	while (ctrl == 1)
	{
		choice = 0;
		system("cls");

		cout << "1 - Enroll a student" << endl;
		cout << "2 - Course Registration" << endl;
		cout << "3 - Attendance" << endl;
		cout << "4 - Marks" << endl;
		cout << "5 - Course Withdraw" << endl;
		cout << "6 - Exit" << endl;
		cout << endl;
		cout << "Enter Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1://enroll
			displayGraphic("Enroll.jpg");

			if (enroll.Login() == 1)
			{
				while (choice2 != 5)
				{
					//teacher menu.
					choice2 = enroll.Menu();

					switch (choice2)
					{
					case 1://view student
						enroll.viewAllStudents();
						break;
					case 2://new students
						enroll.AddData();
						break;
					case 3://remove student
						enroll.removeStudent();
						break;
					case 4://edit student
						enroll.editStudent();
						break;
					case 5://exit choice 1
						displayGraphic("Exit.jpg");
						break;
					default:
						playSound();
						break;
					}
				}
			}
			else
			{
				playSound();
			}
			break;

		case 2:
			choice2 = 0;//resetting

			displayGraphic("Registration.jpg");

			if (reg.Login() == 1)
			{
				while (choice2 != 4)
				{
					choice2 = reg.Menu();

					switch (choice2)
					{
					case 1:
						reg.viewCourses();
						break;
					case 2:
						reg.Availablecourse();
						break;
					case 3:
						reg.Registercourse();
						break;
					case 4:
						displayGraphic("Exit.jpg");
						break;
					default:
						playSound();
						break;
					}
				}
			}
			else
			{
				playSound();
			}
			break;

		case 3:
			choice2 = 0;//resetting

			displayGraphic("Attendance.jpg");

			if (attend.Login() == 1)
			{
				while (choice2 != 3)
				{
					choice2 = attend.Menu();

					switch (choice2)
					{
					case 1:
						attend.viewAttendance();
						break;
					case 2:
						attend.markAttendance();
						break;
					case 3:
						displayGraphic("Exit.jpg");
						break;
					default:
						playSound();
						break;
					}
				}
			}
			else
			{
				playSound();
			}
			break;

		case 4:
			choice2 = 0;//resetting

			displayGraphic("Marks.jpg");

			if (marks.Login() == 1)
			{
				while (choice2 != 3)
				{
					choice2 = marks.Menu();

					switch (choice2)
					{
					case 1:
						marks.viewMarks();
						break;
					case 2:
						marks.AssignMarks();
						break;
					case 3:
						displayGraphic("Exit.jpg");
						break;
					default:
						playSound();
						break;
					}
				}
			}
			else
			{
				playSound();
			}
			break;

		case 5:
			choice2 = 0;//resetting

			displayGraphic("Withdraw.jpg");

			if (withdraw.Login() == 1)
			{
				while (choice2 != 3)
				{
					choice2 = withdraw.Menu();

					switch (choice2)
					{
					case 1:
						withdraw.viewCourses();
						break;
					case 2:
						withdraw.dropcourse();
						break;
					case 3:
						displayGraphic("Exit.jpg");
						break;
					default:
						playSound();
						break;
					}
				}
			}
			else
			{
				playSound();
			}
			break;

		case 6:
			playSound();
			displayGraphic("Exit.jpg");
			ctrl = 0;
			break;

			//choice switch.
		default:
			playSound();
			sfml_text(" -----------------------  \n Invalid Input \n -----------------------  ");
			cout << "No such choice exit" << endl;
			ctrl = 0;
			break;
		}
	}
	return 0;
}