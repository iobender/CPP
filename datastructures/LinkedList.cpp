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
bool LinkedList<T>::add(int index, const T& elt) {
	if(index == 0) {
		node * next= head;
		head= new node;
		head->data= elt;
		head->next= next;
	} else {
		node * curr= head;
		int currIndex= 0;
		while(currIndex < index - 1 && curr->next != nullptr) {
			currIndex++;
			curr= curr->next;
		}
		if(currIndex == index - 1) {
			node * next= curr->next;
			curr->next= new node;
			curr->next->data= elt;
			curr->next->next= next;
		} else {
			throw out_of_range("Index out of Bounds in LinkedList<T>::add");
		}
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
