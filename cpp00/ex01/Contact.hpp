#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>


class Contact
{
private:
    int index;
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_num;
    std::string darkest_secret;
public:
    void set_index(int index);
    void set_firstname(std::string str);
    void set_lastname(std::string str);
    void set_nickname(std::string str);
    void set_phone_num(std::string str);
    void set_darkest_secret(std::string str);

    std::string get_firstname(void);
    std::string get_lastname(void);
    std::string get_nickname(void);
    std::string get_phone_num(void);
    std::string get_darkest_secret(void);
};



#endif