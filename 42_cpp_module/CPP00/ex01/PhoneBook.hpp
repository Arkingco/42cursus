#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

#define MAX_CONTACT 8

class PhoneBook
{
  private:
    Contact contact[8];
    int     idx;

  public:
    PhoneBook();

    void ADD();
    void SEARCH(PhoneBook phone_book);
};

#endif
