#pragma once
//#ifndef Admin_H
//#define Admin_H

#ifndef coder_H
#define coder_H

#include <string>
using namespace std;

class coder
{
protected:
	int marks, P, A;
	string stuID, courseName1, courseName2, courseName3, courseName4, courseName;
	char grade;

public:
	coder();


	~coder();
};

#endif