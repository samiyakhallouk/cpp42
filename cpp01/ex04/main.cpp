#include <iostream>
#include <fstream>
#include <string>

int replace(const std::string s1, const std::string s2, const std::string filename)
{
    std::string line;
    std::ofstream outfile;
    std::ifstream infile;
    size_t found;

    infile.open(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return (1);
    }
    outfile.open((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error opening new file!" << std::endl;
        return (1);
    }
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            outfile << line.substr(pos, found - pos);
            outfile << s2;
            pos = found + s1.length();
        }

        outfile << line.substr(pos);
        if (!infile.eof())
            outfile << '\n';
    }
    infile.close();
    outfile.close();
    return (0);
}

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;

    if (ac != 4)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }

    s1 = av[2];
    s2 = av[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 is empty" << std::endl;
        return (1);
    }
    if (replace(s1, s2, av[1]))
        return (1);
    return (0);
}