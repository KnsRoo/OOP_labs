#include "Bus.h"

Bus::Bus(std::string driver, std::string brand, int number, int year, int mileage){
        this->driver  = driver;
        this->brand   = brand;
        this->number  = number;
        this->year    = year;
        this->mileage = mileage;
}

Bus::~Bus()
{
    //dtor
}

void Bus::info(){
    std::cout<<this->driver<<std::endl<<this->brand<<std::endl<<this->number<<std::endl<<this->year<<std::endl<<this->mileage<<std::endl;
    std::cout<<"--------------"<<std::endl;
}
