#include "CommandLine.h"
#pragma warning (disable : 4996)

void CommandLine::add_command()
{
	std::cin >> command;
	std::cin.ignore();
}
void CommandLine::set_name_space(String& sampleName)
{
	while (true)
	{
		std::cin.get(letter);

		if (letter == ' ' || letter == '\n')
			break;

		sampleName.push_back(letter);
	}
}
void CommandLine::set_name(String& sampleName)
{
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		sampleName.push_back(letter);
	}
}


void CommandLine::copy_apps_from_file(String& file_name)
{
	std::ofstream file;
	file.open(file_name.get_str());
	Vector<Appointment> copy_apps = calendar.get_app();

	for (int i = 0; i < copy_apps.size(); i++)
	{
		int len_name = strlen(copy_apps.at(i).get_name());
		int len_note = strlen(copy_apps.at(i).get_note());
		file << copy_apps.at(i).get_date().get_day();
		file << '|';
		file << copy_apps.at(i).get_date().get_mounth();
		file << '|';
		file << copy_apps.at(i).get_date().get_year();
		file << '|';
		file << copy_apps.at(i).get_stime().get_hours();
		file << '|';
		file << copy_apps.at(i).get_stime().get_minutes();
		file << '|';
		file << copy_apps.at(i).get_etime().get_hours();
		file << '|';
		file << copy_apps.at(i).get_etime().get_minutes();
		file << '|';
		file << copy_apps.at(i).get_date().get_day();
		file << '|';
		file.write(copy_apps.at(i).get_name(),len_name );
		file.write(copy_apps.at(i).get_note(), len_note);
		file << '\n';
	}

	file.close();
}
void CommandLine::new_file()
{
	std::ofstream newFile(file_name.get_str()); // Създаваме празен файл, както е по условие.
	std::cerr << "Such file doesn't exist. A new empty file with the given name was created for you" << std::endl;
	newFile.close();
}

void CommandLine::read_from_file(std::ifstream& file)
{
	file.open(file_name.get_str());

	char ch = 'a';
	int curr_row = 1;
	int curr_col = 1;

	String empty_str;
	

	String temp_str;
	

	bool is_empty = true;

	while (true)
	{
		file.get(ch);

		if (file.eof())
			break;
		if (ch == '\n')
		{
			if (!is_empty)
			{
	
			}

			curr_row++;
			curr_col = 1;

			temp_str = empty_str;
	

			is_empty = true;
		}

		else if (ch != ',')
		{
			temp_str.push_back(ch);
			is_empty = false;
		}
		else if (ch == ',')
		{

			curr_col++;

			temp_str = empty_str;

		}
	}

}

void CommandLine::save(String& file_name)
{
	copy_apps_from_file(file_name);

	std::cout << "Successfully saved " << file_name.get_str() << std::endl;
}

void CommandLine::saveas()
{
	String userChosenfile_name; // Създаваме името на файла, в което потребителят иска да запише промените.

	set_name(userChosenfile_name);

	copy_apps_from_file(userChosenfile_name);

	std::cout << "Successfully saved another " << userChosenfile_name.get_str() << std::endl;
}

void CommandLine::close() const
{
	std::cout << "Successfully closed" << " " << file_name.get_str();
}

void CommandLine::exit() const
{
	std::cout << "Exiting the program..." << std::endl;
}

void CommandLine::help() const
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open <file>                opens <file>" << std::endl;
	std::cout << "close			            closes currently opened file" << std::endl;
	std::cout << "save			            saves the currently open file" << std::endl;
	std::cout << "saveas <file>	            saves the currently open file in <file>" << std::endl;
	std::cout << "help			            prints this information" << std::endl;
	std::cout << "exit			            exists the program" << std::endl;
}

void CommandLine::open()
{
	std::cout << "Write exit to stop the program." << std::endl;

	String empty_file_name;
	std::ifstream file;

	while (strcmp(command, "exit") != 0)
	{
		add_command();

		if (strcmp(command, "open") == 0)
		{
			set_name(file_name);

			file.open(file_name.get_str());

			if (file.fail())
			{
				new_file();

				file.open(file_name.get_str());
			}
			else
				std::cout << "Successfully opened " << file_name.get_str() << std::endl;

			file.close();

			//read_from_file(file);

			while (true)
			{
				add_command();
				if (strcmp(command, "open") == 0)
					std::cout << "You have to close the file before opening another one." << std::endl;

				else if (strcmp(command, "save") == 0)
					save(file_name);

				else if (strcmp(command, "saveas") == 0)
					saveas();

				else if (strcmp(command, "close") == 0)
				{
					close();
					file.close();

					file_name = empty_file_name;
					break;
				}

				else if (strcmp(command, "exit") == 0)
				{
					//exit();
					return;
				}

				else if (strcmp(command, "help") == 0)
					help();
				else if (strcmp(command, "book") == 0)
					book();
				else if (strcmp(command, "unbook") == 0)
					unbook();
				else if (strcmp(command, "agenda") == 0)
					agenda();
				else if (strcmp(command, "change") == 0)
					change();
				else if (strcmp(command, "find") == 0)
					find();
				else if (strcmp(command, "holiday") == 0)
					holiday();
				else if (strcmp(command, "findslot") == 0);
				else if (strcmp(command, "findslotwith") == 0);
				else if (strcmp(command, "merge") == 0);
				else if (strcmp(command, "busydays") == 0)
					busydays();
					
			}
		}
	}
}


void CommandLine::book() {
	String book_info;
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		book_info.push_back(letter);
	}
	calendar.add_app(book_info);
}

void CommandLine::unbook() {
	String unbook_info;
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		unbook_info.push_back(letter);
	}
	unbook_info.push_back(' ');
	unbook_info.push_back('a');
	unbook_info.push_back('a ');
	unbook_info.push_back(' ');
	unbook_info.push_back(' ');
	unbook_info.push_back('a');
	unbook_info.push_back('a ');
	unbook_info.push_back('\n');
	app.set_appointment(unbook_info);
	calendar.rem_app(app);
	app = *new Appointment();
}

void CommandLine::agenda(){
	String agenda_info;
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		agenda_info.push_back(letter);
	}
	date.set_date_str(agenda_info.get_str());
	calendar.agenda_date(date);
	date = *new Date();
}

void CommandLine::find() {
	String book_info;
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		book_info.push_back(letter);
	}
	calendar.find_str(book_info);
}

void CommandLine::holiday() {
	String holiday_info;
	while (true)
	{
		std::cin.get(letter);

		if (letter == '\n')
			break;

		holiday_info.push_back(letter);
	}
	date.set_date_str(holiday_info.get_str());
	calendar.add_holiday(date);
	date = *new Date();
}

void CommandLine::change() {
	String date_str, stime, option, value;
	set_name_space(date_str);
	set_name_space(stime);
	set_name_space(option);
	set_name(value);
	date.set_date_str(date_str.get_str());
	time.set_time_str(stime.get_str());
	calendar.change_date(date, time, option, value);
	
}

void CommandLine::busydays() {
	String from, to;
	Date to_date;
	set_name_space(from);
	set_name(to);
	date.set_date_str(from.get_str());
	to_date.set_date_str(to.get_str());
	calendar.busydays(date, to_date);
}