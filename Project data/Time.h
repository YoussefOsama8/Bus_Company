#pragma once
#include <iostream>
using namespace std;
class Time
{
	int HH;
	int MM;
public:
	Time(int Hours=0, int Minutes=0);
	void SetTime(int Hour, int Min);
	int GetHours();
	int GetMin();
	void Print();
	Time operator - (Time T);
	~Time();
};

