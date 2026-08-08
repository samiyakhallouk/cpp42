#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other): v(other.v), d(other.d){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        v = other.v;
        d = other.d;
    }
    return (*this);
}

std::vector<int> PmergeMe::jacobsthol(size_t size)
{
    size_t U0 = 0;
    size_t U1 = 1;
    std::vector<int> jacob;
    
    while (U0 <= size)
    {
        size_t end = U1;

        if (end > size)
            end = size;

        for (size_t i = end; i > U0; --i)
            jacob.push_back(i - 1);

        size_t U2 = U1 + 2 * U0;

        U0 = U1;
        U1 = U2;
    }
    return (jacob);
}

std::vector<int> PmergeMe::insert(size_t size)
{
    std::vector<int> jacob = jacobsthol(size);
    for (size_t i = 0; i < jacob.size(); i++)
    {
        std::cout << jacob[i] << " ";
    }
    std::cout << std::endl;
    return (jacob);
}

std::vector<int> PmergeMe::fordJohnsonSortV(std::vector<int>& v)
{
    if (v.size() <= 1)
        return v;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<std::pair<int, int> > pairs;
    int straggler;
    bool hasLeftOver = (v.size()%2 != 0);

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i] < v[i + 1])
            std::swap(v[i], v[i + 1]);
        pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    if (hasLeftOver)
    {
        straggler = v.back();
    }

    main = fordJohnsonSortV(main);

    std::vector<int> order = jacobsthol(pend.size());

    if (hasLeftOver)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(pos, straggler);
    }
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = order[i];

        std::vector<int>::iterator bigIt = std::find(main.begin(), main.end(), pairs[index].first);
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), bigIt, pend[index]);
        main.insert(pos, pend[index]);
    }
    return(main);
}

std::deque<int> PmergeMe::fordJohnsonSortD(std::deque<int>& d)
{
    if (d.size() <= 1)
        return d;
    std::deque<int> main;
    std::deque<int> pend;
    std::deque<std::pair<int, int> > pairs;
    int straggler;
    bool hasLeftOver = (d.size()%2 != 0);

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] < d[i + 1])
            std::swap(d[i], d[i + 1]);
        pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    if (hasLeftOver)
    {
        straggler = d.back();
    }
    
    main = fordJohnsonSortD(main);
    
    std::vector<int> order = jacobsthol(pend.size());

    if (hasLeftOver)
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(pos, straggler);
    }
    
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = order[i];

        std::deque<int>::iterator bigIt = std::find(main.begin(), main.end(), pairs[index].first);
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), bigIt, pend[index]);
        main.insert(pos, pend[index]);
    }
    return(main);
}

void PmergeMe::parsing(int size, char **av)
{
    long n;
    
    if (size < 2)
        throw std::runtime_error("Error!");
    
    for (int i = 1; i < size; i++)
    {
        std::string arg(av[i]);
        if (arg.empty() || arg.size() > 10)
            throw std::runtime_error("Error!");    
        if (arg.find('+', arg.size()-1) != std::string::npos)
            throw std::runtime_error("Error!");

        std::stringstream ss(arg);
        while (ss >> n)
        {
            if (n < 0 || n > INT_MAX)
                throw std::runtime_error("Error!");    
            v.push_back(n);
            d.push_back(n);
        }
        if (!(ss.eof()))
            throw std::runtime_error("Error!");    
    }
}

void PmergeMe::fordJohnsonAlgo(int size, char **arg)
{
    parsing(size, arg);
    print_before();

    clock_t startV = clock();
    v = fordJohnsonSortV(v);
    clock_t endV = clock();
    double timeV = (double)(endV - startV) * 1000000 / CLOCKS_PER_SEC;

    clock_t startD = clock();
    d = fordJohnsonSortD(d);
    clock_t endD = clock();
    double timeD = (double)(endD - startD) * 1000000 / CLOCKS_PER_SEC;

    print_after();
    std::cout << "Time to process a range of "
            << v.size() << " elements with std::vector : "
            << timeV << " us\n";


    std::cout << "Time to process a range of "
            << v.size() << " elements with std::deque : "
            << timeD << " us\n";

    
}

void PmergeMe::print_before()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_after()
{
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
