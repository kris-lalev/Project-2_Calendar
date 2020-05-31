#include <fstream>
#include "Calendar.h"


const int MAX_SIZE_OF_COMMAND = 20;
#include "Calendar.h"
class CommandLine
{
private:
	String file_name; /**< Undetermined length of the name of a file. */
	String value;
	Date date;
	Time time;
	Appointment app;
	Calendar calendar;

	char command[MAX_SIZE_OF_COMMAND];
	char letter;

	void set_name(String& sampleName);  /**< new_cells to set the name of a file. */
	void set_name_space(String& sampleName);

	/** 
	* The functions mentioned below are new_cellss for the realisation of the main command open().
	* Consequently, they are private member functions.
	* @see new_file() @see read_from_file()
	*/
	void copy_apps_from_file(String& difffile_name); 
	void new_file(); /**< If the pointed out file doesn't exist, this function creates new, empty one. */
	/**
	* Extracts the content of a file and creates a "virtual table". The user works on it and depending on
	* whether he wants to save the changes or not, he uses the commands save() / saveas() or close() respectively.
	*/
	void read_from_file(std::ifstream& file);

public:
	void add_command();

	void book();
	void unbook();
	void agenda();
	void change();
	void find();
	void holiday();
	void findslot();
	void findslotwith();
	void merge();
	void busydays();
	void save(String& file_name);
	void saveas();
	void close() const;
	void exit() const;
	void help() const;


	void open();
};