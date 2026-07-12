#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template<typename T>
class Array
{
    private:
        T *array;
        unsigned int n;
    public:
        Array() : array(NULL), n(0)
        {}
        Array(unsigned int n)
        {
            this->n = n;
            this->array = new T[n]();
        }
        Array(Array& other)
        {
            n = other.n;
            array = new T[n];
            for (size_t i = 0; i < n; i++)
            {
                array[i] = other.array[i];
            }
        }
        Array& operator=(Array& other)
        {
            if (this != &other)
            {
                delete [] array;
                n = other.n;
                array = new T[n];
                for (size_t i = 0; i < n; i++)
                {
                    array[i] = other.array[i];
                } 
            }
            return (*this);
        }
        ~Array()
        {
            delete [] array;
        }
        T& operator[](unsigned int i)
        {
            if (n <= i)
                throw std::out_of_range("index is out of range");
            return (array[i]);
        }
        
        const T& operator[](unsigned int i) const
        {
            if (n <= i)
                throw std::out_of_range("index is out of range");
            return (array[i]);
        };

        unsigned int size() const
        {
            return (n);
        };
};



#endif