#include "Appointment.h"
bool Appointment::set_appointment(String& str) {
	int len = strlen(str.get_str());
	String temp, empty;
	size_t count = 0;
	for (; count < 10;  count++)
	{
		temp.push_back(str.get_str()[count]);
	}
	date.set_date_str(temp.get_str());
	
	temp = empty;
	for (count = 11; count < 16; count++)
	{
		temp.push_back(str.get_str()[count]);
	}
	
	start.set_time_str(temp.get_str());
	temp = empty;
	for (count = 17; count < 22; count++)
	{
		temp.push_back(str.get_str()[count]);
	}
	end.set_time_str(temp.get_str());
	temp = empty;
	for (count = 23; str.get_str()[count] != ' '; count++)
	{
		temp.push_back(str.get_str()[count]);
	}
	name = temp;
	count++;
	temp = empty;
	for (; count < len; count++)
	{
		temp.push_back(str.get_str()[count]);
	}
	note = temp;
	if (start > end)
		return false;
	return true;
}

Date Appointment::get_date() const {
	return date;
}
Time Appointment::get_stime() const {
	return start;
}
Time Appointment::get_etime() const {
	return end;
}
const char* Appointment::get_note() const {
	return note.get_str();
}

const char* Appointment::get_name() const {
	return name.get_str();
}


void Appointment::set_date(Date& new_date) {
	date = new_date;
}

void Appointment::set_stime(Time& time){
	start = time;
}

void Appointment::set_etime(Time& time) {
	end = time;
}

void Appointment::set_name(String& value) {
	name = value;
}
void Appointment::set_note(String& value) {
	note = value;
}

bool  Appointment::operator==(const Appointment& other) {
	if (date == other.get_date() && start == other.get_stime() && end == other.get_etime())
	{
		return true;
	}
	return false;
}
void Appointment::print() const {
	std::cout << " Appointment: ";
	name.print();
	std::cout << " On: ";
	date.print();
	std::cout << " From: ";
	start.print();
	std::cout << " To: ";
	end.print();
	std::cout << " Note: ";
	note.print();
}


int Appointment::dur() {
	return diff_time(start, end);
}