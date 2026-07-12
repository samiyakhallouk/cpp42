#include "Contact.hpp"

void Contact::set_index(int index)
{
    index = index;
}
void Contact::set_firstname(std::string str)
{
    firstname = str;
}
void Contact::set_lastname(std::string str)
{
    lastname = str;
}
void Contact::set_nickname(std::string str)
{
    nickname = str;
}
void Contact::set_phone_num(std::string str)
{
    phone_num = str;
}
void Contact::set_darkest_secret(std::string str)
{
    darkest_secret = str;
}

std::string Contact::get_firstname(void)
{
    return(firstname);
}
std::string Contact::get_lastname(void)
{
    return(lastname);
}
std::string Contact::get_nickname(void)
{
    return(nickname);
}
std::string Contact::get_phone_num(void)
{
    return(phone_num);
}
std::string Contact::get_darkest_secret(void)
{
    return(darkest_secret);
}