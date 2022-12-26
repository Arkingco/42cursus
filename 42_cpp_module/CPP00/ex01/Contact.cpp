#include "Contact.hpp"
#include <iostream>

const std::string Contact::contact_element_string[NUMBER_OF_ELEMENT] = {"FIRST_NAME", "LAST_NAME", "NICK_NAME",
                                                                        "PHONE_NUMBER", "DARKEST_SECRET"};

std::string Contact::get_element(e_Contact_Element element)
{
    return elements[element];
}
void Contact::set_element(e_Contact_Element element, std::string content)
{
    elements[element] = content;
}
