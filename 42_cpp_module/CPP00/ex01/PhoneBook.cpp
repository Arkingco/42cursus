#include "PhoneBook.hpp"
#include "error.cpp"

PhoneBook::PhoneBook()
{
	this->idx = 1;
}

void set_element()
{
	std::string element;
}

void PhoneBook::ADD()
{
	std::string element;

	for (int i = 0; i<NUMBER_OF_ELEMENT; ++i)
	{
		std::getline(std::cin, element);
		std::cout << "enter" << contact_element[i] << " : " << std::endl;
		this->contact[this->idx].set_element(i, element);
		if (is_cin_succes())
		{
			i = i - 1;
			element.clear();
			continue;
		}
		element.clear();
	}
	this->idx = (this->idx + 1) % 8;
}

void PhoneBook::SEARCH(PhoneBook phone_book)
{
	std::cout << "-------------------------------------" << std::endl;

	for (int i=0; i<NUMBER_OF_ELEMENT - 1; ++i)
		std::cout << "|" << std::cout.width(10) << contact_element[i];

	for(int i=0; i<MAX_CONTACT; ++i)
	{
		for (int j=0; j<NUMBER_OF_ELEMENT - 1; ++j)
		{
			std::cout	<< "|"
						<< std::cout.width(10) 
						<< phone_book.contact[i].get_element(j);
		}
		std::cout << "|";
	}
	std::cout << "-------------------------------------" << std::endl;
}

void PhoneBook::get_contact()
{
}
