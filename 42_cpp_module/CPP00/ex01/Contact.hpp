#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

typedef enum Contact_Element
{
    FIRST_NAME = 0,
    LAST_NAME,
    NICK_NAME,
    PHONE_NUMBER,
    DARKEST_SECRET,
    NUMBER_OF_ELEMENT,
} e_Contact_Element;

class Contact
{
  private:
    std::string elements[NUMBER_OF_ELEMENT];

  public:
    const static std::string contact_element_string[NUMBER_OF_ELEMENT];
    std::string              get_element(e_Contact_Element element);
    void                     set_element(e_Contact_Element element, std::string content);
};

#endif
