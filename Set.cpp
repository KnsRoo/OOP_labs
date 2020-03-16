#include "Set.h"

template <class T>
Set<T>::Set(std::vector<T> elements){
        for_each(elements.begin(), elements.end(), [this](T &n){
            this->elements.push_back(n);
        });
}

template <class T>
Set<T>::Set(Set &set){
        std::vector<T> elements = set.get_elements();
        for_each(elements.begin(), elements.end(), [this](T &n){
            this->elements.push_back(n);
        });
}

template <class T>
Set<T>::~Set()
{
    //dtor
}

template <class T>
bool Set<T>::is_in(T element){
    bool ret = false;
    for(size_t i=0;i<get_elements().size();i++){
        if (element == this->elements[i]) ret = true;
    }
    return ret;
}

template <class T>
Set<T>* Set<T>::operator=(Set<T> &set){
    return new Set<T>(set);
}

template <class T>
Set<T>* Set<T>::operator+(Set<T> &set){
    std::vector<T> united;
    for(size_t i=0;i<get_elements().size();i++){
        united.push_back(get_elements()[i]);
    }
    std::vector<T> tmp = set.get_elements();
    for(size_t i=0;i<tmp.size();i++){
        if (!(is_in(tmp[i]))) united.push_back(tmp[i]);
    }
    return new Set(united);
}

template <class T>
Set<T>* Set<T>::operator*(Set<T> &set){
    std::vector<T> intersected;
    std::vector<T> tmp = set.get_elements();
    for(size_t i=0;i<tmp.size();i++){
        if (is_in(tmp[i])) intersected.push_back(tmp[i]);
    }
    return new Set(intersected);
}

template <class T>
Set<T>* Set<T>::operator-(Set &set){
    std::vector<T> differenced;
    for(size_t i=0;i<get_elements().size();i++){
        differenced.push_back(get_elements()[i]);
    }
    std::vector<T> tmp = set.get_elements();
    for(size_t i=0;i<tmp.size();i++){
        if (is_in(tmp[i])) { differenced.erase(remove(differenced.begin(), differenced.end(), tmp[i]), differenced.end()); }
    }
    return new Set(differenced);
}

template <class T>
void Set<T>::print(){
    for_each(this->elements.begin(), this->elements.end(), [](T &n){
            std::cout<<n<<" ";
    });
    std::cout<<std::endl;
}

template class Set<int>;
