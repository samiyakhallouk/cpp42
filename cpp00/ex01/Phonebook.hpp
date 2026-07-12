#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact contacts[8];
		int i;
		int prev_i;
	public:
		PhoneBook();
		~PhoneBook();		
		Contact get_contact(int index);
		void add_contacts(Contact user);
		int count_user();
};

#endif