# include <iostream>
# include "Contact.hpp"

const std::string Contact::contact_element_string[NUMBER_OF_ELEMENT] = {
		"FIRST_NAME",
		"LAST_NAME",
		"NICK_NAME",
		"PHONE_NUMBER",
		"DARKEST_SECRET"
};

std::string Contact::get_element(int element) {
	return elements[element];
}
void Contact::set_element(int element, std::string content)
{
	elements[element] = content;
}
