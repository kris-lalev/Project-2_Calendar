#include <iostream>
#include "Time.h"

Time::Time():
	m_minutes{ 0 },
	m_hours{ 0 }{

}
Time::Time(short int hours, short int minutes):
	m_minutes{ minutes },
	m_hours {hours}
{

}

void Time::set_time(short int hours, short int minutes)
{
	
	m_minutes = minutes;
	m_hours = hours;
}
void Time::set_hours(short int hours) {
	m_hours = hours;
}
void Time::set_minutes(short int minutes) {
	m_minutes = minutes;

}
void Time::set_time_str(const char* str) {
	short int temp = 0;
	int len = strlen(str);
	bool fin = false;
	int item = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ':')
		{
			item++;
			fin = true;
		}
		else if (i == len - 1) {
			item++;
			fin = true;
			temp = temp * 10 + str[i] - '0';
		}
		else {
			temp = temp * 10 + str[i] - '0';
		}
		 if (item == 1 && fin == true)
		{
			set_hours(temp);

			temp = 0;
			fin = false;
		}
		else if (item == 2 && fin == true)
		{
			set_minutes(temp);
			temp = 0;
			fin = false;
		}

	}

}
short int Time::get_hours() const {
	return m_hours;
}
short int Time::get_minutes() const {
	return m_minutes;
}
void Time::print() const {
	std::cout << m_hours << ':' << m_minutes;
}

bool  Time::operator==(const Time& other) const {
	if (m_hours != other.get_hours())
		return false;
	if (m_minutes != other.get_minutes())
		return false;
	return true;
}




bool  Time::operator>(const Time& other) const {
	if (m_hours > other.get_hours())
		return true;
	else if (m_hours == other.get_hours())
	{
		if (m_minutes > other.get_minutes())
			return true;
		else if (m_minutes == other.get_minutes())
		{
			return false;
		}
		else
			return false;
	}
	else
		return false;
}

int Compare(const Time& first, const Time& second) {
	if (first.get_hours() > second.get_hours()) {
		return -1;
	}
	else if (first.get_hours() < second.get_hours()) {
		return 1;
	}
	else
	{
		if (first.get_minutes() > second.get_minutes())
			return -1;
		else if (first.get_minutes() < second.get_minutes())
			return 1;
		else
		{
			return 0;
		}
	}
}

int diff_time( Time first, Time second) {

	int hrs = std::abs(first.get_hours() - second.get_hours());
	hrs *= 60;
	int mins = std::abs(first.get_minutes() - second.get_minutes());
	if (first.get_hours() > second.get_hours()) {
		if (first.get_minutes() > second.get_minutes())
			return hrs+ mins;
		else if (first.get_minutes() < second.get_minutes())
			return hrs - mins;
		else
			return hrs;
	}
	else if (first.get_hours() < second.get_hours()) {
		if (first.get_minutes() > second.get_minutes())
			return hrs - mins;
		else if (first.get_minutes() < second.get_minutes())
			return hrs + mins;
		else
			return hrs;
	}
	else  {
		return mins;
		
	}
	return 0;
}