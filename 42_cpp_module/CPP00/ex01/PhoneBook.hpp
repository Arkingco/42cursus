
#ifndef PHONEBOOK
#define PHONEBOOK

# include <iostream>
# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
	private:
		Contact contact[8];
		int idx;

	public:
		PhoneBook();

		void ADD();
		void SEARCH(PhoneBook phone_book);
		void EXIT();
		void get_contact();
};

#endif
