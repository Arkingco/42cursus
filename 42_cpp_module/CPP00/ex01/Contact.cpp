#ifndef CONTACT

# include <iostream>
# include "Contact.hpp"

std::string Contact::get_element(int element) {
	return elements[element];
}
void Contact::set_element(int element, std::string content)
{
	elements[element] = content;
}

#endif
