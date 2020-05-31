#pragma once
#include "Appointment.h"
#include "Vector.hpp"
class Calendar
{
private:
	Vector<Appointment> appointments;
	Vector<Date> holidays;
	void delete_app(int id) {
		appointments.erase(id);
	}
public:
	Vector<Appointment> get_app() {
		return appointments;
	}
	void rem_app(Appointment a) {
		for (int i = 0; i < appointments.size(); i++)
		{
			
			if (appointments.at(i) == a) {
				std::cout << std::endl << "An appintment was removed successfully" << std::endl;
				delete_app(i);
				break;
			}
		}
	}
	void add_app(String& str) {
		Appointment new_app;
		if (new_app.set_appointment(str))
		{
			
			if (can_add_app(new_app))
			{
				
				appointments.push_back(new_app);
				std::cout << "Appointment added!" << std::endl;
				

			}
			else
				std::cout << "Cant2 add appointment!" << std::endl;
		}
		else
			std::cout << "Cant add appointment!" << std::endl;

	}

	bool can_add_app(Appointment& one) const { 
		bool comp = true;
		for (int i = 0; i <appointments.size(); i++)
		{
			if (one.get_date() == appointments.at(i).get_date()) {
				if (Compare(one.get_stime(), appointments.at(i).get_stime()) == 1 &&(Compare(one.get_etime(), appointments.at(i).get_stime()) == -1   || Compare(one.get_etime(), appointments.at(i).get_stime()) == 0))
					comp = false;
				if ((Compare(one.get_stime(), appointments.at(i).get_stime()) == -1 || Compare(one.get_stime(), appointments.at(i).get_stime()) == 0) && Compare(one.get_stime(), appointments.at(i).get_etime()) == 1)
					comp = false;
			}
		}
		if (!is_holiday(one.get_date()))
		{
			if (comp)
				return true;
		}
		else
			std::cout << "This day is a holiday!\n";
		return false;
	}

	void busydays(Date& from, Date& to) {
		Vector<Date> days;
		Vector<int>  days_dur;
		from.print();
		to.print();
		if (from > to)
		{
			std::cout << "Wrong input! First date is after second." << std::endl;
			return;
		}
		int curr_day = 0;
		while (!(from == to))
		{

			curr_day = 0;
			days.push_back(from);
			
			for (int i = 0; i < appointments.size(); i++)
			{
				if (appointments.at(i).get_date() == from) {
					curr_day += appointments.at(i).dur();

				}
			}
			days_dur.push_back(curr_day);
			from.next_date();
		}
		int smallest = 0;
		Date temp_day;
		int temp_dur;
		bool change = false;
		for (int i = 0; i < days_dur.size(); i++)
		{
			smallest = days_dur.size() - i - 1;
			for (int j = 0; j < days_dur.size() - i; j++)
			{
				if (days_dur.at(j) < days_dur.at(smallest))
				{
					smallest = j;
					change = true;
				}
			}
			if (change)
			{
			temp_day = days.at(smallest);
			temp_dur = days_dur.at(smallest);
			days.erase(smallest);
			days_dur.erase(smallest);
			days.push_back(temp_day);
			days_dur.push_back(temp_dur);
			}
			
		}

		for (int j = 0; j < days_dur.size(); j++)
		{
			std::cout << "Day: ";
			days.at(j).print();
			std::cout << " Has work hours: " << days_dur.at(j) << std::endl;

		}
	}

	bool is_holiday(const Date& date) const
	{
		for (int i = 0; i < holidays.size(); i++)
		{
			if (date == holidays.at(i)) {
				return true;
			}
		}
	}

	void add_holiday(Date& date) {
		if(!is_holiday(date))
			holidays.push_back(date);
		else
			std::cout << "Holiday already added!" << std::endl;
	}

	void agenda_date(Date& date) const {
		
		for (int i = 0; i < appointments.size(); i++)
		{
			if (appointments.at(i).get_date() == date)
			{
				appointments.at(i).print(); 
				std::cout << std::endl;
			}
		}
	}

	void change_date(Date& date, Time& time, String& option, String& value) {
		for (int i = 0; i < appointments.size(); i++)
		{
			if (appointments.at(i).get_date() == date && appointments.at(i).get_stime() == time) {
				if (!strcmp(option.get_str(), "date"))
				{
					Date new_date;
					new_date.set_date_str(value.get_str());
					appointments.at(i).set_date(new_date);

				}
				else if (!strcmp(option.get_str(), "starttime"))
				{
					Time new_stime;
					new_stime.set_time_str(value.get_str());
					appointments.at(i).set_stime(new_stime);
				}
				else if (!strcmp(option.get_str(), "endtime"))
				{
					Time new_etime;
					new_etime.set_time_str(value.get_str());
					appointments.at(i).set_etime(new_etime);

				}
				else if (!strcmp(option.get_str(), "name"))
				{
					appointments.at(i).set_name(value);
				}
				else if (!strcmp(option.get_str(), "note"))
				{
					appointments.at(i).set_note(value);
				}
				break;
			}

		}
	}

	void find_str(String& text) {
		for (int i = 0; i < appointments.size(); i++)
		{
			if (search_in_for(appointments.at(i).get_note(), text.get_str()) || search_in_for(appointments.at(i).get_name(), text.get_str()))
			{
				appointments.at(i).print();
				std::cout << std::endl;
			}
		}
	}

};

