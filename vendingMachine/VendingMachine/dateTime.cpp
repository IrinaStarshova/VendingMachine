#include "dateTime.h"
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

DateAndTime::DateAndTime()
{
	time_t t = time(NULL);
	localtime_s(&dateAndTime, &t);
}

bool DateAndTime::operator <(const DateAndTime& rhs) const
{
	if (dateAndTime.tm_year == rhs.dateAndTime.tm_year)
		return (dateAndTime.tm_mon == rhs.dateAndTime.tm_mon) 
		? dateAndTime.tm_mday < rhs.dateAndTime.tm_mday : dateAndTime.tm_mon < rhs.dateAndTime.tm_mon;
	else
		return dateAndTime.tm_year < rhs.dateAndTime.tm_year;
}

bool DateAndTime::operator ==(const DateAndTime& rhs) const
{
	return dateAndTime.tm_mday == rhs.dateAndTime.tm_mday 
		&& dateAndTime.tm_mon == rhs.dateAndTime.tm_mon && dateAndTime.tm_year == rhs.dateAndTime.tm_year;
}

void DateAndTime::initExpirationDate()
{
	dateAndTime.tm_mday += 1 + rand() % 7;
	mktime(&dateAndTime);
}

string DateAndTime::getTimeStringForFileName() const
{
	stringstream tString;
	tString << dateAndTime.tm_hour << "." << dateAndTime.tm_min << "." << dateAndTime.tm_sec;
	return tString.str();
}

string DateAndTime::getTimeString() const
{
	stringstream tString;
	tString << dateAndTime.tm_hour << ":" << dateAndTime.tm_min << ":" << dateAndTime.tm_sec;
	return tString.str();
}

string DateAndTime::getDateString() const
{
	stringstream dString;
	dString << 1900 + dateAndTime.tm_year << "." << 1 + dateAndTime.tm_mon << "." << dateAndTime.tm_mday;
	return dString.str();
}