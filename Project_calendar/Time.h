#pragma once
class Time
{
private:
	short int m_hours;
	short int m_minutes;
public:
	Time();
	Time(short int hours, short int minutes);
	void set_time(short int, short int);
	void set_hours(short int hours);
	void set_minutes(short int minutes);
	void set_time_str(const char*);

	bool  operator==(const Time& other) const;
	bool  operator>(const Time& other) const;

	short int get_minutes() const;
	short int get_hours() const;
	void print() const;
};

int Compare(const Time& first, const Time& second);
int diff_time(Time& first, Time& second);
