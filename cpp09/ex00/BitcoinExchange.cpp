#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {*this = other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        m = other.m;
        file = other.file;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

int BitcoinExchange::parse_val(std::string& value)
{
    if (value[0] != ' ')
    {
        std::cout << "Error: bad input => " << value << std::endl;
        return 1;
    }
    value = value.substr(1);
    std::stringstream ss(value);
    float v;
    if (!(ss >> v) || !(ss.eof()))
    {
        std::cout << "Error: bad input => " << value << std::endl;
        return 1;
    }
    if (value[0] == '-')
    {
        std::cout << "Error: not a positive number."<< std::endl;
        return 1;
    }
    
    if (v < 0 || v > 1000 || value.size() > 4)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    
    return 0;
}

int BitcoinExchange::parse_date(std::string& date)
{
    if (date[date.size() - 1] != ' ')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    date = date.substr(0, date.size() - 1);
    std::stringstream ss(date);
    std::string year, month, day;
    
    if (!(std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day)))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    
    std::cout << year << " ";
    std::cout <<month << " ";
    std::cout << day<< std::endl;

    std::stringstream yr(year), mt(month), dy(day);
    int y,m,d;
    
    if (!(yr >> y) || !yr.eof() || !(mt >> m) || !mt.eof() || !(dy >> d) || !dy.eof())
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    
    if (y < 2009 || y > 2022 || year.size() != 4)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    if (m < 1 || m > 12 || month.size() != 2)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    if (d < 1 || d > 31 || day.size() != 2)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    return 0;
}

int BitcoinExchange::parse_line(std::string& line)
{
    std::string date, value;
    std::stringstream ss(line);

    if (std::getline(ss, date, '|') && std::getline(ss, value))
    {
        // std::cout << value<< std::endl;
        if (parse_date(date))
            return 1;
        if (parse_val(value))
            return 1;
        std::map<std::string, float>::iterator it = m.find(date);
        if (it != m.end())
            return 0;
        std::stringstream v(value);
        float value;
        v >> value;
        it = m.lower_bound(date);
        std::cout << date << " => " << value << " = " << (it->second) * value << std::endl;
        return 0;
    }
    std::cout << "Error: bad input => " << line << std::endl;
    return 1;
}

void BitcoinExchange::fill_map()
{
    std::ifstream data_file("data.csv");
    if (!data_file.is_open())
        throw std::runtime_error("Error : couldn´t open file!");
    
    std::string line, date;
    float val;
    while (std::getline(data_file, line))
    {
        size_t pos = 0;
        if ((pos = line.find(',')) != std::string::npos)
        {
            date = line.substr(0, pos);
            std::stringstream ss(line.substr(pos + 1));
            ss >> val;
        }
        m[date] = val;
        // std::cout << m[date] << std::endl;
    }
}

void BitcoinExchange::shearch_on()
{
    fill_map();
    std::ifstream input("input.txt");
    if (!input.is_open())
        throw std::runtime_error("Error : couldn´t open file!");
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        if (parse_line(line))
        {
            continue;
        }
    }
    
}