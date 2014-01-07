/*
 * Matthew Bender
 * Jan 7, 2014
 * 
 * LinkedList implementation in C++
 */
#include <iostream>
#include "LinkedList.hpp"
using namespace std;

template<class T>
LinkedList<T>::LinkedList() {
	head= nullptr;
}

template<class T>
bool LinkedList<T>::add(const T& elt) {
	if(head == nullptr) {
		head= new node;
		head->data= elt;
		head->next= nullptr;
	} else {
		node * curr= head;
		while(curr-> next != nullptr)
			curr= curr->next;
		curr->next= new node;
		curr->next->data= elt;
		curr->next->next= nullptr;
	}

	return true;
}

template<class T>
string LinkedList<T>::toString() const {
	stringstream ret;
	ret << "[ ";
	node * curr= head;
	while(curr != nullptr) {
		ret << curr->data << " ";
		curr= curr->next;
	}
	ret << "]\n";
	return ret.str();
}

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
	os << list.toString();
	return os;
}
