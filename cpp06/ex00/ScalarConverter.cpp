#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

void print_special(std::string str)
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

void print_char(double i)
{
    if (i < 0  || i > 127)
        std::cout << "char: " << "impossible" << std::endl;
    else
    {
        char c = static_cast<char>(i);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
    }
}


void convert_char(std::string str)
{
    char c = str[0];

    print_char(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
    
}

void convert_int(std::string str)
{
    double i = std::atof(str.c_str());
    
    print_char(i);
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    if (std::isinf(i) || i < -FLT_MAX || i > FLT_MAX)
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;

    if (std::isinf(i))
        std::cout << "double: " << "impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convert_float(std::string str)
{
    double f = std::atof(str.c_str());

    print_char(f);
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    if (std::isinf(f) || f < -FLT_MAX || f > FLT_MAX)
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::isinf(f))
        std::cout << "double: " << "impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convert_double(std::string str)
{
    double d = std::atof(str.c_str());

    print_char(d);
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    if (std::isinf(d) || d < -FLT_MAX || d > FLT_MAX)
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    if (std::isinf(d))
        std::cout << "double: " << "impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

int is_special(std::string str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return 0;
    return 1;   
}

int is_double(std::string str)
{
    size_t i = 0;
    if ((str[i] == '-' || str[i] == '+'))
        i++;
    int flag_dot = 0;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return 1;
        if (str[i] == '.')
        {
            if (flag_dot)
                return 1;
            flag_dot = 1;
            if (i == 0)
            {
                i++;
                if (i < str.length() && !std::isdigit(str[i]))
                    return 1;
            }
        }
    }
    return 0; 
}

int is_float(std::string str)
{
    size_t i = 0;
    int flag_dot = 0;
    int flag_f = 0;
    if ((str[i] == '-' || str[i] == '+'))
        i++;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.' && (str[i] != 'f' || i != str.length() - 1))
            return 1;
        if (str[i] == '.')
        {
            if (flag_dot)
                return 1;
            flag_dot = 1;
            if (str[0] == '.')
            {
                i++;
                if (i < str.length() && !std::isdigit(str[i]))
                    return 1;
            }
        }
        if (str[i] == 'f')
        {
            if (flag_f == 1 || flag_dot == 0)
                return 1;
            flag_f = 1;
        }
    }
    return 0;
}

int is_int(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] == '+')))
            return 1;
    }
    return 0;
}

Type check_input(std::string str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return CHAR;
    else if (!is_int(str))
        return INT;
    else if (!is_double(str))
        return DOUBLE;
    else if (!is_float(str))
        return FLOAT;
    else if (!is_special(str))
        return SPECIAL;
    else
        return INVALID;
    
}

void print_error()
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "impossible" << std::endl;
    std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.empty())
    {
        print_error();
        return;
    }
    
    Type type = check_input(literal);
    
    if (type == CHAR)
        convert_char(literal);
    else if (type == INT)
        convert_int(literal);
    else if (type == FLOAT)
        convert_float(literal);
    else if (type == DOUBLE)
        convert_double(literal);
    else if (type == SPECIAL)
        print_special(literal);
    else
        print_error();
}