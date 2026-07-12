#include "PhoneBook.hpp"
#include "Contact.hpp"


std::string check_lenght(std::string str)
{
	std::string res;
	if (str.length() > 10)
		return (res = str.substr(0, 9) + ".", res);
	return (str);
}

void display_info(int index, PhoneBook *contacts)
{
	std::cout << "firstname: " << contacts->get_contact(index).get_firstname() << std::endl ;
	std::cout << "lastname: " << contacts->get_contact(index).get_lastname() << std::endl ;
	std::cout << "nickname: " << contacts->get_contact(index).get_nickname() << std::endl ;
	std::cout << "phone number: " << contacts->get_contact(index).get_phone_num() << std::endl ;
	std::cout << "darkest secret: " << contacts->get_contact(index).get_darkest_secret() << std::endl ;
}

int is_space_or_tab(std::string& str)
{
    int i = 0;
    int f = 0;
     
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            f += 1;
        if (f == 1 && i == 0)
            return (1);
        if (f > 1)
            return (1);
        i++;
    }
    if (str[i - 1] == ' ' || str[i - 1] == '\t')
        return (1);
    return (0); 
}

void	print_error(int n)
{
	if (std::cin.eof())
		exit(0);
	if (n == 1)
		std::cout << "\033[1;31m" << "Invalid input!" << "\033[0m" << std::endl;
	else if (n == 2)
		std::cout << "\033[1;31m" << "PhoneBook is empty." << "\033[0m" << std::endl;
	else if (n == 3)
		std::cout << "\033[1;31m" << "Wrong index!" << "\033[0m" << std::endl;
}

int for_add(PhoneBook *contacts, Contact user)
{
	std::string firstname, lastname, nickname, phone_num, darkest_secret;
	while (1)
	{
		std::cout << "firstname: ";
		std::getline(std::cin, firstname);
		if (firstname.empty() || is_space_or_tab(firstname) || std::cin.eof())
		{
			print_error(1);
			continue;;
		}
		int i = 0, flag = 0;
		while (firstname[i])
		{
			if (std::isprint(firstname[i]) == 0)
			{
				flag = 1;	
				break;
			}
			i++;
		}
		if (flag == 1)
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "lastname: ";
		std::getline(std::cin, lastname);
		if (lastname.empty() || is_space_or_tab(lastname) || std::cin.eof())
		{
			print_error(1);
			continue;
		}
		int i = 0, flag = 0;
		while (lastname[i])
		{
			if (std::isprint(lastname[i]) == 0)
			{
				flag = 1;	
				break;
			}
			i++;
		}
		if (flag == 1)
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.empty() || is_space_or_tab(nickname) || std::cin.eof())
		{
			print_error(1);
			continue;
		}
		int i = 0, flag = 0;
		while (nickname[i])
		{
			if (std::isprint(nickname[i]) == 0)
			{
				flag = 1;	
				break;
			}
			i++;
		}
		if (flag == 1)
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "phone number: ";
		std::getline(std::cin, phone_num);
		if (phone_num.empty() || is_space_or_tab(phone_num) || std::cin.eof())
		{
			print_error(1);
			continue;
		}
		int i = 0, flag = 0;
		while (phone_num[i])
		{
			if (std::isdigit(phone_num[i]) == 0)
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag)
			continue;
		break;
	}
	while (1)
	{
		std::cout << "darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty() || is_space_or_tab(darkest_secret))
		{
			print_error(1);
			continue;
		}
		int i = 0, flag = 0;
		while (darkest_secret[i])
		{
			if (std::isprint(darkest_secret[i]) == 0)
			{
				flag = 1;	
				break;
			}
			i++;
		}
		if (flag == 1)
			continue;
		else
			break;		
	}
	
	user.set_firstname(firstname);
	user.set_lastname(lastname);
	user.set_nickname(nickname);
	user.set_phone_num(phone_num);
	user.set_darkest_secret(darkest_secret);

	contacts->add_contacts(user);
	return (0);
}

int for_search(PhoneBook *contacts)
{
	int j = 0;
	int count = contacts->count_user();
	if (count == 0)
	{
		print_error(2);
		return (1);
	}
	std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10)
		<< "firstname" << "|" << std::setw(10) << "lastname"
		<< "|" << std::setw(10) << "nickname" << "|" << std::endl;
	while (j < count)
	{
		std::cout << "|" << std::setw(10) << j + 1
			<< "|" << std::setw(10) << check_lenght(contacts->get_contact(j).get_firstname())
			<< "|" << std::setw(10) << check_lenght(contacts->get_contact(j).get_lastname())
			<< "|" << std::setw(10) << check_lenght(contacts->get_contact(j).get_nickname())
			<< "|" << std::endl;
		j++;
	}
	std::string index;
	int ind;
	std::cout << "enter index: " ;
	std::getline(std::cin, index);
	if (std::cin.eof())
		exit(0);
	ind = std::atoi(index.c_str());
	if (ind > 0 && ind <= count)
		display_info(ind - 1, contacts);
	else
		print_error(3);
	return (0);
}

int main()
{
	PhoneBook contacts;
	Contact user;
	std::string input;
	
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "enter (ADD-SEARCH-EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			if (for_add(&contacts, user))
			{
				continue;
			}
		}
		else if (input == "SEARCH")
		{
			if (for_search(&contacts))
				continue;
		}
		else if (input == "EXIT")
			return (0);
		else
		{
			print_error(1);
			continue;
		}
	}
	return 0;
}
