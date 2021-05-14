#include "myDate.h"
#include<iostream>
using namespace std;
/**
updates a day month and year with a julian date
@param JD the updated julian date
@param m referenced month
@param d referenced d
@param y referenced year
*/
void Julian2Greg(int JD, int& m, int& d, int& y)
{
	int L, N, I, J, K;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;


	//update the date

	y = I;
	m = J;
	d = K;

}

/**
converts a gregorian date to julian
@param m the month
@param d the day
@param y the year
@return the julian date of the date passed
*/
int Greg2Julian(int m, int d, int y)
{
	int jd;
	jd = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
	return jd;
}



/**
default constructor. This will set the date to May 11, 1959
*/
myDate::myDate()
{
	month = 5, day = 11, year = 1959;
}

/**
overloaded constructor. creates a specified date
@param m the month
@param d the day
@param y the year
*/
myDate::myDate(int m, int d, int y)
{
	month = m, day = d, year = y;

	//check for validity and normalize

	if (month < 1 || month > 12)
	{
		month = 5, day = 11, year = 1959;
	}
	if (day < 1 || day > 31)
	{
		month = 5, day = 11, year = 1959;
	}
	
}

/**
displays the date
*/
void myDate::display()
{
	cout << months[month - 1] << " " << day << ", " << year;
}

/**
returns the day in int form
@return the date
*/
int myDate::getDay()
{
	return day;
}

/**
return the month in int form
@return the month
*/
int myDate::getMonth()
{
	return month;
}

/**
returns the year 
@return the year
*/
int myDate::getYear()
{
	return year;
}

/**
calculates the days between using the julian conversion
@param d the date to compare
@return the days between date d and the current date
*/
int myDate::daysBetween(myDate d)
{
	return Greg2Julian(d.getMonth(), d.getDay(), d.getYear()) - Greg2Julian(month, day, year);
}

/**
Increases the date by a set integer
@param n the integer to be increased by
*/
void myDate::increaseDate(int n)
{
	int jd = Greg2Julian(month, day, year) + n;
	Julian2Greg(jd, month, day, year);

}

/**
Decreases the date by a set integer
@param n the integer to be decreased by
*/
void myDate::decreaseDate(int n)
{
	int jd = Greg2Julian(month, day, year) - n;
	Julian2Greg(jd, month, day, year);
}

/**
returns the day of the week that the date falls on
@return the string representation of the weekday
*/
string myDate::dayName()
{
	return days[Greg2Julian(month, day, year) % 7];
}

/**
returns the number of days since the beginning of the year
@return the number of days.
*/
int myDate::dayOfYear()
{
	myDate base = myDate(1, 1, year);
	return (-1* daysBetween(base)) + 1;
}