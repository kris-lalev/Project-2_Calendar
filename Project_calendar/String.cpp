#include "String.h"
#pragma warning (disable : 4996)

String::String()
{
	capacity = 4;
	str = new char[capacity] {' '};
	currentEl = 0;
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String()
{
	free();
}

void String::copyFrom(const String& other)
{
	capacity = other.capacity;
	currentEl = other.currentEl;
	str = new char[capacity + 1];
	strcpy(str, other.str);
}

void String::free()
{
	delete[] str;
}

void String::resize()
{
	capacity *= 2;
	char* biggerArr = new char[capacity];
	strcpy(biggerArr, str);
	free();
	str = biggerArr;
}

void String::push_back(char element)
{
	if (currentEl == capacity - 1)
		resize();
	str[currentEl] = element;
	currentEl++;
	str[currentEl] = '\0';
}

void String::set_str(const char* str)
{
	delete[] this->str;
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);

	capacity = strlen(str);
	currentEl = strlen(str);
}

const char* String::get_str() const
{
	return str;
}

void String::print() const
{
	std::cout << str;
}


bool search_in_for(const char* text, const char* words) {
	int len_text = strlen(text);
	int len_words = strlen(words);
	bool found = false;
	for (int i = 0; i < len_text; i++)
	{
		if (text[i] == words[0])
		{
			found = true;
			for (int j = 0; j < len_words; j++)
			{
				if (text[i + j] != words[j]) {
					found = false;
					break;
				}
			}
		}
		if (found == true)
			break;
	}
	return found;

}