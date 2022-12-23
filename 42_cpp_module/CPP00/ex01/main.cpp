#include <iostream>
#include "PhoneBook.hpp"
#include "error.hpp"

int main()
{
	std::string	line;
	PhoneBook	phone_book;

	while (1)
	{
		std::cout << "choose the command! (ADD / SEARCH / EXIT) :";
		getline(std::cin, line);
		if (!is_cin_success())
			std::exit(1);
		if (line.compare("ADD") == 0)
			phone_book.ADD();
		else if (line.compare("SEARCH") == 0)
			phone_book.SEARCH(phone_book);
		else if (line.compare("EXIT") == 0)
			return (0);
		else
			print_error(WRONG_STRING);
		std::cin.clear();
	}
}
