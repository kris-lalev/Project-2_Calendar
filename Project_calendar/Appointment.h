#pragma once
#include "Date.h"
#include "Time.h"
#include "String.h"
class Appointment
{
private:
	Date date;
	Time start;
	Time end;
	String name;
	String note;
	
public:
	bool set_appointment(String& str);
	bool  operator==(const Appointment& other);
	void print() const;
	void set_date(Date& date);
	void set_stime(Time& time);
	void set_etime(Time& time);
	void set_name(String& value);
	void set_note(String& value);
	Date get_date() const;
	Time get_stime() const;
	Time get_etime() const;
	int dur();
	const char* get_note() const;
	const char* get_name() const;
};


