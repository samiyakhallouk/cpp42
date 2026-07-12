#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    i = 0;
    prev_i = 0;
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contacts(Contact user)
{
    contacts[i % 8] = user;
    if (i < 8)
        prev_i++;
    i++;
}

Contact PhoneBook::get_contact(int index)
{
    return contacts[index];
}

int PhoneBook::count_user()
{
    return(prev_i);
}