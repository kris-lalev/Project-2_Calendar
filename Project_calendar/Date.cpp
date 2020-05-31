#include <iostream>
#include "Date.h"

Date::Date() :
	m_year{ 0 },
	m_mounth{ 0 },
	m_day{ 0 } {
	
}
Date::Date(short int mounth, short int year , short int day) :
	m_year{ year },
	m_mounth{ mounth },
	m_day{day}
{

}
void Date::set_date_str(const char* str)
{
	short int temp = 0;
	int len = strlen(str);
	bool fin = false;
	int item = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == ':')
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
			set_year(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 2 && fin == true)
		{
			set_mounth(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 3 && fin == true)
		{
			set_day(temp);
			temp = 0;
			fin = false;
		}
	}
}

void Date::set_date(short int mounth, short int year, short int day)
{
	m_year = year;
	m_mounth = mounth;
	m_day = day;
}
void Date::set_year(short int year) {
	m_year = year;
}
void Date::set_mounth(short int mounth) {
	m_mounth = mounth;

}
void Date::set_day(short int day) {
	m_day = day;
}
short int Date::get_mounth() const {
	return m_mounth;
}
short int Date::get_year() const {
	return m_year;
}
short int Date::get_day() const {
	return m_day;
}
void Date::print() const {
	std::cout << m_year << '-' << m_mounth << '-' << m_day;
}

bool  Date::operator==(const Date& other) const {
	if (m_year != other.get_year())
		return false;
	if (m_mounth != other.get_mounth())
		return false;
	if (m_day != other.get_day())
		return false;
	return true;
}

bool  Date::operator>(const Date& other) const {
	if (m_year > other.get_year())
		return true;
	else if (m_year == other.get_year())
	{
		if (m_mounth > other.get_mounth())
			return true;
		else if (m_mounth == other.get_mounth())
		{
			if (m_day > other.get_day())
				return true;
			else if (m_day == other.get_day())
			{
				return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void Date::next_date() {
	if (m_mounth == 1 || m_mounth == 3 || m_mounth == 5 || m_mounth == 7 || m_mounth == 8 || m_mounth == 10)
	{
		if (m_day < 31)
			m_day++;
		else 
		{
			m_day = 1;
			m_mounth++;
		}
	}
	else if (m_mounth == 4 || m_mounth == 6 || m_mounth == 9 || m_mounth == 11)
	{
		if (m_day < 30)
			m_day++;
		else
		{
			m_day = 1;
			m_mounth++;
		}
	}
	else if (m_mounth == 12)
	{
		if (m_day < 31)
			m_day++;
		else
		{
			m_day = 1;
			m_mounth = 1;
			m_year++;
		}
	}
	else if (m_mounth == 2) {
		bool leap = is_leap_year(m_year);
		if (m_day < 28 + leap)
			m_day++;
		else
		{
			m_day = 1;
			m_mounth++;
		}
	}
}

bool is_leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;

	return 0;
}