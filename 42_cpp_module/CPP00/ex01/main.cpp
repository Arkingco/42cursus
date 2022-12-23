#include <iostream>
#include "PhoneBook.hpp"

void cmd_ADD(PhoneBook phone_book)
{

}

void cmd_SEARCH(PhoneBook phone_book)
{

}

int process_cmd(std::string line, PhoneBook phone_book)
{
	if (line.compare("ADD"))
	{
		phone_book.ADD();
	}
	else if (line.compare("SEARCH"))
	{
		phone_book.SEARCH(phone_book);
	}
	else if (line.compare("EXIT"))
	{
		return (0);
	}
	return (1);
}

int main()
{
	std::string	line;
	PhoneBook	phone_book;

	while (1)
	{
		getline(std::cin, line);
		if (process_cmd(line, phone_book) == 0)
			break ;
	}
	return (1);
}
