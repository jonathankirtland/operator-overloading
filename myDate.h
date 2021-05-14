#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;
class myDate
{
public:
	//constructors
	myDate();
	myDate(int m, int d, int y);

	//displays the date
	void display();

	//increase the date
	void increaseDate(int n);

	//decrease the date
	void decreaseDate(int n);

	//count the days between date d and current date
	int daysBetween(myDate d);

	//getters
	int getMonth();
	int getDay();
	int getYear();

	//returns the days past new years
	int dayOfYear();

	//returns the day of the week
	string dayName();

private:
	int month, day, year;
	string months [12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

};

//convert gregorian to julian
int Greg2Julian(int m, int d, int y);

//converts a julian date to gregorian by updating the month day and year
void Julian2Greg(int JD, int& m, int& d, int& y);

#endif
