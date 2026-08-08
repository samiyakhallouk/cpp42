#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <ctime>
#include <vector>
#include <deque>


class PmergeMe
{
    private:
        std::vector<int> v;
        std::deque<int> d;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);
        ~PmergeMe();

        void fordJohnsonAlgo(int, char **);
        void parsing(int, char **);
        void print_before() ;
        void print_after();

        std::vector<int> fordJohnsonSortV(std::vector<int>&);
        std::deque<int> fordJohnsonSortD(std::deque<int>&);

        std::vector<int> insert(size_t);
        std::vector<int> jacobsthol(size_t);
};


#endif