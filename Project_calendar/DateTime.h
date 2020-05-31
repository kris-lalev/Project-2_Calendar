#pragma once
#include "Date.h"
#include "Time.h"
#include "String.h"
class DateTime
{
private:
	Date m_date;
	Time m_time;
public:
	short int get_mounth() const;
	short int get_year() const;
	short int get_day() const;
	Date get_date() const;
	Time get_time() const;
	short int get_minutes() const;
	short int get_hours() const;
	bool  operator==(const DateTime& other);
	int datetimecmp(const DateTime& other);
	void set_datetime_str(const char*);
	void set_datetime(const Date& date, const Time& time);
	void print() const;
};

