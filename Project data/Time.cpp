#include "Time.h"


Time::Time(int Hours, int Minutes)
{
	SetTime(Hours, Minutes);
}
void Time::SetTime(int Hour, int Min)
{
	if (Hour < 0 || Hour>24)
		HH = 0;
	if (Min < 0)
		MM = 0;

	if (Min > 60 && Hour > 0)
	{
		HH = Hour++;
		MM = Min - 60;
	}
	if (Min >= 0 || Min < 60 && Hour >= 0 || Hour < 24)
	{
		HH = Hour;
		MM = Min;
	}

}
int Time::GetHours()
{
	return HH;

}
int Time::GetMin()
{
	return MM;
}
void Time::Print()
{
	cout << "The time is " << HH << ":" << MM << endl;
}

Time Time::operator - (Time T)
{
	if (MM- T.GetMin() < 0)
	{
		MM = (MM-T.GetMin()  )+ 60;
		
		if ( T.GetHours()-HH < 0)
		{
			HH=abs(HH - T.GetHours());
			HH--;
		}
		else
		{
			HH = abs(HH - T.GetHours());
			HH--;
		}
	}
	else
	{
		MM = MM-T.GetMin() ;
		if (HH - T.GetHours() < 0)
		{
			HH = abs(HH - T.GetHours());
		}
		else
		{
			HH = abs(HH - T.GetHours());
		}
	}
	return Time(HH, MM);
}
Time::~Time()
{

}
