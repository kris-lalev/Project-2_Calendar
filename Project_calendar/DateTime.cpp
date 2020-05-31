#include "DateTime.h"

void DateTime::set_datetime(const Date& date, const Time& time) {
	m_date = date;
	m_time = time;
}

void DateTime::set_datetime_str(const char* str) {
	short int temp = 0;
	int len = strlen(str);
	bool fin = false;
	int item = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == ':' )
		{
			item++;
			fin = true;
		}
		else if( i == len - 1) {
			item++;
			fin = true;
			temp = temp * 10 + str[i] - '0';
		}
		else {
			temp = temp * 10 + str[i] - '0';
		}

		if (item == 1 && fin == true)
		{
			m_date.set_year(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 2 && fin == true)
		{
			m_date.set_mounth(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 3 && fin == true)
		{
			m_date.set_day(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 4 && fin == true)
		{
			m_time.set_hours(temp);
			temp = 0;
			fin = false;
		}
		else if (item == 5 && fin == true)
		{
			m_time.set_minutes(temp);
			temp = 0;
			fin = false;
		}
		
	}

}
void DateTime::print() const {
	m_date.print();
	std::cout << ' ';
	m_time.print();
}
short int DateTime::get_mounth() const {
	return  m_date.get_mounth();
		
}
short int DateTime::get_year() const {
	return m_date.get_year();

}
short int DateTime::get_day() const {
	return m_date.get_day();
}
short int DateTime::get_hours() const {
	return m_time.get_hours();
}
short int DateTime::get_minutes() const {
	return m_time.get_minutes();
}

bool  DateTime::operator==(const DateTime& other) {
	if (m_date == other.get_date() && m_time == other.get_time())
		return true;
	return false;

}

int DateTime::datetimecmp(const DateTime& other) {
	if (*this == other)
		return 0;
	
}