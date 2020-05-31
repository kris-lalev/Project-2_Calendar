#pragma once
class Date
{
private:
	short int m_year;
	short int m_mounth;
	short int m_day;
public:
	Date();
	Date(short int, short int, short int);
	void set_date(short int, short int, short int);
	void set_date_str(const char* str);
	void set_year(short int);
	void set_mounth(short int);
	void set_day(short int);
	short int get_mounth() const;
	short int get_year() const;
	short int get_day() const;
	void print() const;
	bool operator==(const Date& other) const;
	bool  operator>(const Date& other) const;
	void next_date();
};


bool is_leap_year(int year);
