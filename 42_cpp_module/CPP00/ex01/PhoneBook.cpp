#include "PhoneBook.hpp"
#include "error.hpp"

PhoneBook::PhoneBook()
{
    this->idx = 0;
}

void PhoneBook::ADD()
{
    std::string content;

    for (int i = 0; i < NUMBER_OF_ELEMENT; ++i)
    {
        std::cout.width(15);
        std::cout << Contact::contact_element_string[i] << " : ";
        std::getline(std::cin, content);
        if (!is_cin_success())
            std::exit(0);
        if (content.compare("") == 0)
        {
            print_error(EMPTY_STRING);
            i = i - 1;
            continue;
        }
        this->contact[this->idx].set_element(static_cast<e_Contact_Element>(i), content);
        std::cin.clear();
    }
    this->idx = (this->idx + 1) % 8;
}

void print_only_ten_word(std::string content)
{
    if (content.length() >= 10)
    {
        std::cout << content.substr(0, 9) + ".";
        return;
    }
    std::cout << content;
}

void PhoneBook::SEARCH(PhoneBook phone_book)
{
    std::string idx;

    std::cout << "|";
    std::cout.width(10);
    std::cout << "IDX";
    for (int i = 0; i < NUMBER_OF_ELEMENT - 2; ++i)
    {
        std::cout << "|";
        std::cout.width(10);
        std::cout << Contact::contact_element_string[i];
    }
    std::cout << "|" << std::endl;

    for (int i = 0; i < MAX_CONTACT; ++i)
    {
        std::cout << "|";
        std::cout.width(10);
        std::cout << i + 1;
        for (int j = 0; j < NUMBER_OF_ELEMENT - 2; ++j)
        {
            std::cout << "|";
            std::cout.width(10);
            print_only_ten_word(phone_book.contact[i].get_element(static_cast<e_Contact_Element>(j)));
        }
        std::cout << "|" << std::endl;
    }

    while (1)
    {
        std::cout << "choose the idx(user) you want! (1 ~ 8) : ";
        std::getline(std::cin, idx);
        if (!is_cin_success())
            std::exit(1);
        if (idx.length() == 1 && idx[0] >= '1' && idx[0] <= '8')
            break;
        std::cout << "please choose the right idx! " << std::endl;
    }

    for (int i = 0; i < NUMBER_OF_ELEMENT; ++i)
    {
        std::cout.width(15);
        std::cout << Contact::contact_element_string[i] << " : ";
        std::cout << phone_book.contact[idx[0] - '1'].get_element(static_cast<e_Contact_Element>(i)) << std::endl;
    }
}
