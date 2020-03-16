#ifndef BUS_H
#define BUS_H
#include <stdio.h>
#include <iostream>
#include <fstream>
#include<algorithm>
#include <string>
#include <random>
#include <time.h>

class Bus
{
    public:
        Bus(std::string driver, std::string brand, int number, int year, int mileage);
        virtual ~Bus();
        void info();
        inline std::string get_driver(){return this->driver;}
        inline std::string get_brand(){return this->brand;}
        inline int get_number(){return this->number;}
        inline int get_year(){return this->year;}
        inline int get_mileage(){return this->mileage;}

    protected:

    private:
        std::string   driver, brand;
        int   number, year, mileage;
};

#endif // BUS_H
