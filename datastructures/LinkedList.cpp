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
	if(index < 0 || index >= size)
		throw out_of_range("Index out of bounds in LinkedList<T>::get");
	int currIndex= 0;
	node * curr= head;
	while(currIndex != index) {
		currIndex++;
		curr= curr->next;
	}
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
	if(index < 0 || index > size)
		throw out_of_range("Index out of Bounds in LinkedList<T>::add");
	if(index == 0) {
		node * next= head;
		head= new node;
		head->data= elt;
		head->next= next;
	} else {
		node * curr= head;
		int currIndex= 0;
		while(currIndex != index - 1) {
			currIndex++;
			curr= curr->next;
		}
		node * next= curr->next;
		curr->next= new node;
		curr->next->data= elt;
		curr->next->next= next;
	}
	size++;
	return true;
}

template<class T>
T LinkedList<T>::set(int index, const T& elt) {
	if(index < 0 || index >= size)
		throw out_of_range("Index out of Bounds in LinkedList<T>::set");
	int currIndex= 0;
	node * curr= head;
	while(currIndex != index) {
		currIndex++;
		curr= curr->next;
	}
	T ret= curr->data;
	curr->data= elt;
	return ret;
}

template<class T>
T LinkedList<T>::remove(int index) {
	if(index < 0 || index >= size)
		throw out_of_range("Index out of Bounds in LinkedList<T>::remove");
	if(index == 0) {
		node * old= head;
		head= head->next;
		T ret= old->data;
		delete old;
		size--;
		return ret;
	} else {
		int currIndex= 0;
		node * curr= head;
		while(currIndex != index - 1) {
			currIndex++;
			curr= curr->next;
		}
		node * old= curr->next;
		curr->next= curr->next->next;
		T ret= old->data;
		delete old;
		size--;
		return ret;
	}
}

template<class T>
bool LinkedList<T>::removeElt(const T& elt) {
	if(head == nullptr)
		return false;
	if(head->data == elt) {
		node * old= head;
		head= head->next;
		delete old;
		size--;
		return true;
	}
	node * curr= head;
	while(curr->next != nullptr && curr->next->data != elt)
		curr= curr->next;
	if(curr->next == nullptr)
		return false;
	node * old= curr->next;
	curr->next= curr->next->next;
	delete old;
	size--;
	return true;
}

template<class T>
void LinkedList<T>::clear() {
	while(head != nullptr) {
		node * old= head;
		head= head->next;
		delete old;
		size--;
	}
}

template<class T>
int LinkedList<T>::find(const T& elt) const {
	int index= 0;
	node * curr= head;
	while(curr != nullptr && curr->data != elt) {
		index++;
		curr= curr->next;
	}
	if(curr == nullptr)
		return -1;
	else
		return index;
}

template<class T>
T * LinkedList<T>::toArr() const {
	T * arr= new T [size];
	node * curr;
	int index;
	for(curr= head, index= 0; index < size; curr= curr->next, index++)
		arr[index]= curr->data;
	return arr;
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
