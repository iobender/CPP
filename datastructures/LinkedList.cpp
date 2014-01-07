/*
 * Matthew Bender
 * Jan 7, 2014
 * 
 * LinkedList implementation in C++
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "LinkedList.hpp"
using namespace std;

template<class T>
LinkedList<T>::LinkedList() {
	head= nullptr;
	size= 0;
}

template<class T>
int LinkedList<T>::getSize() const {
	return size;
}

template<class T>
T LinkedList<T>::get(int index) const {
	if(index < 0)
		throw out_of_range("Index out of bounds in LinkedList<T>::get");
	int currIndex= 0;
	node * curr= head;
	while(currIndex < index && curr != nullptr) {
		currIndex++;
		curr= curr->next;
	}
	if(curr == nullptr)
		throw out_of_range("Index out of bounds in LinkedList<T>::get");
	else
		return curr->data;
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
	size++;
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
	size++;
	return true;
}

template<class T>
T LinkedList<T>::set(int index, const T& elt) {
	if(index < 0)
		throw out_of_range("Index out of Bounds in LinkedList<T>::set");
	int currIndex= 0;
	node * curr= head;
	while(currIndex < index && curr != nullptr) {
		currIndex++;
		curr= curr->next;
	}
	if(curr == nullptr)
		throw out_of_range("Index out of Bounds in LinkedList<T>::set");
	T ret= curr->data;
	curr->data= elt;
	return ret;
}

template<class T>
T LinkedList<T>::remove(int index) {
	if(index < 0)
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
