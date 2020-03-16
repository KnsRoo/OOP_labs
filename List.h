#ifndef LIST_H
#define LIST_H
#include "stdio.h"
#include <iostream>
#include <vector>

class List
{
    public:
        List(std::vector<int> vec);
        virtual ~List();
        void push(int e);
        void pushback(int e);
        void pop();
        void popback();
        int get(int k);
        int size();
        void clear();
        void print();
        bool contains(List lst);

    protected:

    private:
        struct list{
        int inf;
        list *next=0;
        };
        list *head = new list;
};

#endif // LIST_H
