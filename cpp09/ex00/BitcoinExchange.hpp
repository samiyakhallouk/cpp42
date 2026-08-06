#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>



class BitcoinExchange
{
    private:
        std::map<std::string, double> m;
        std::string file;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        ~BitcoinExchange();

        void shearch_on(char *);
        void fill_map();
        int parse_line(std::string&);
        int parse_date(std::string&);
        int parse_val(std::string&);
};









#endif