#include <stdio.h>
#include <iostream>
#include <fstream>
#include<algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <random>
#include <time.h>
#include <Windows.h>
#include <Bus.h>
#include <Set.h>
#include <List.h>

void printall(std::vector<Bus> Buses){
    std::for_each(Buses.begin(), Buses.end(), [](Bus &bus){
        bus.info();
    });
}

void printbusnumber(std::vector<Bus> Buses, int number){
    std::cout<<"По маршруту "<<number<<" ходят следующие автобусы:"<<std::endl;
    std::for_each(Buses.begin(), Buses.end(), [number](Bus &bus){
        if (bus.get_number() == number) bus.info();
    });
}

void printbusyear(std::vector<Bus> Buses){
    std::cout<<"Больше 10 лет эксплуатируются следующие автобусы:"<<std::endl;
    std::for_each(Buses.begin(), Buses.end(), [](Bus &bus){
        if ((2020 - bus.get_year()) > 10) bus.info();
    });
}

void printbusmileage(std::vector<Bus> Buses){
    std::cout<<"Больше 10000 пробега у следующих автобусов:"<<std::endl;
    std::for_each(Buses.begin(), Buses.end(), [](Bus &bus){
        if (bus.get_mileage() > 10000) bus.info();
    });
}


Set<int>* function(Set<int> A, Set<int> B){
    Set<int> *C = A+B;
    Set<int> *D = A*B;
    Set<int> *F = *C-(*D);
    return F;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<std::string> myfile;
    std::vector<Bus> Buses;
    std::ifstream file("buses.txt");
    std::string line;
    while (getline(file,line)){ myfile.push_back(line); }
    file.close();
    for (unsigned int i=0; i<myfile.size()/5; i++){
            Buses.push_back(Bus(myfile[i*5],myfile[i*5+1],std::stoi(myfile[i*5+2]),std::stoi(myfile[i*5+3]),std::stoi(myfile[i*5+4])));
    }
    myfile.clear();
    printbusnumber(Buses, 2);
    printbusmileage(Buses);
    printbusyear(Buses);
    std::ifstream file2("set.txt");
    std::vector<int> tmp, vA,vB; std::string a;
    int sz = -1, it = 0;
    while (!(file2.eof())){
        file2>>a;
        if (sz == -1) { sz = std::stoi(a); continue; }
        if (it<sz) { vA.push_back(std::stoi(a)); }
        else       { vB.push_back(std::stoi(a)); }
        it++;
    }
    file2.close();
    Set<int> A(vA);
    Set<int> B(vB);
    A.print();
    B.print();
    Set<int> *G = function(A,B);
    G->print();
    List lA({0,1,2,3});
    List lB({1,2});
    std::cout<<(lA.contains(lB) ? "Содержит" : "Не содержит")<<std::endl;
    return 0;
}
