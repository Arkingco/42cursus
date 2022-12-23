
#ifndef CONTACT
#define CONTACT

# include <iostream>

typedef enum Contact_Element {
	FIRST_NAME,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
	NUMBER_OF_ELEMENT,
} e_Contact_Element;

class Contact
{
	private:
		std::string elements[5];

	public:
		const static std::string 	contact_element_string[NUMBER_OF_ELEMENT];
		std::string 				get_element(int element);
		void 						set_element(int element, std::string content);
};

#endif
