#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <vector>
#include <iterator>
#include <string>

template <class T>
class Set
{
    public:
        Set(std::vector<T> elements);
        Set(Set<T> &set);
        Set* operator+(Set<T> &set);
        Set* operator-(Set<T> &set);
        Set* operator*(Set<T> &set);
        Set* operator=(Set<T> &set);
        virtual ~Set();
        inline std::vector<T> get_elements() { return this->elements; }
        bool is_in(T element);
        void print();

    protected:

    private:
        std::vector<T> elements;
};

#endif // SET_H
