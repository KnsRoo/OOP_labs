#include "List.h"

List::List(std::vector<int> vec){
        list *p = this->head;
        p->inf = vec[0];
        for(size_t i=1;i<vec.size();i++){
            p->next = new list;
            p = p->next;
            p->inf = vec[i];
            }
        p->next = 0;
	}

List::~List()
{
    //dtor
}

void List::push(int e) {
	list *q = new list;
	q->inf = e;
	q->next = this->head;
	this->head = q;
}

void List::pushback(int e) {
	list *p = this->head;
	while (!(p->next) == 0)
		p = p->next;
	list *w = new list;
	w->inf = e;
	w->next = p->next;
	p->next = w;
}

void List::popback() {
	list *p = this->head;
	while (!(p->next->next == 0)) {
		p = p->next;
	}
	list *w;
	w = p->next;
	p->next = w->next;
	delete w;
}

void List::pop() {
	list *w = new list;
	w = this->head;
	this->head = w->next;
	delete w;
}

int List::size() {
	int cnt = 0;
	list *p = this->head;
	while (p) {
		cnt++;
		p = p->next;
	}
	return cnt;
}

bool List::contains(List lst){
    bool ret = true;
    list *A = this->head;
    list *B = lst.head;
    int elem = lst.get(0);
    while (A->inf != elem){
        A = A->next;
    }
    while (B){
        if (A->inf == B->inf){
            A = A->next;
            B = B->next;
        } else {
            ret = false;
            break;
        }
    }
    return ret;
}

void List::clear() {
	while (!(this->head->next == 0)) {
		pop();
	}
}

int List::get(int k) {
	list *p = this->head;
	for (int i = 0; i<k - 1; i++)
		p = p->next;
	return p->inf;
}

void List::print(){
    list *p = this->head;
	if (p == 0) {
		std::cout << "Error! List not created. Press 1 to Create" << std::endl;
	}
	else {
		while (p) {
			std::cout << p->inf << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
}
