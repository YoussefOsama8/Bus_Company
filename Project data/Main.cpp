#include"Time.h"
#include <iostream>
using namespace std;
int main()
{
	Time T1(5,17);
	Time T2(3,34);
	Time T3;
	T3 = T1 - T2;
	T3.Print();

}