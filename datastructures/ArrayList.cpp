#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ArrayList.hpp"
using namespace std;

template<class T>
ArrayList<T>::ArrayList() {
	capacity= DEFAULT_INIT_CAPACITY;
	size= 0;
	arr= new T [capacity];
}

template<class T>
ArrayList<T>::ArrayList(int init_capacity) {
	capacity= init_capacity;
	size= 0;
	arr= new T [capacity];
}

template<class T>
int ArrayList<T>::getSize() const { 
	return size; 
}

template<class T>
int ArrayList<T>::getCapacity() const {
	return capacity;
}

template<class T>
T ArrayList<T>::get(int index) const {
	if(index >= size)
		throw out_of_range("Index out of bounds in ArrayList<T>::get");
	else
		return arr[index];
}

template<class T>
bool ArrayList<T>::add(T elt) {
	if(size == capacity)
		reallocate();
	arr[size++]= elt;
	return true;
}

template<class T>
bool ArrayList<T>::add(int index, T elt) {
	if(index > size)
		throw out_of_range("Index out of bounds in ArrayList<T>::add");
	if(size == capacity)
		reallocate();
	for(int i= size; i > index; i--) 
		arr[i]= arr[i-1];
	arr[index]= elt;
	size++;
	return true;
}

template<class T>
T ArrayList<T>::remove(int index) {
	if(index >= size)
		throw out_of_range("Index out of bounds in ArrayList<T>::remove");
	for(int i= index; i+1 < size; i++) 
		arr[i]= arr[i+1];
	size--;
}

template<class T>
int ArrayList<T>::find(T elt) const {
	for(int i= 0; i < size; i++) {
		if(arr[i] == elt)
			return i;
	}
	return -1;
}

template<class T>
bool ArrayList<T>::reallocate() {
	capacity *= 2;
	T * newarr= new T [capacity];
	for(int i= 0; i < size; i++)
		newarr[i]= arr[i];
	delete [] arr;
	arr= newarr;
}

template<class T>
string ArrayList<T>::toString() const {
	stringstream ret;
	//ret << "Capacity: " << capacity << endl;
	//ret << "Size: " << size << endl;
	ret << '(' << size << '/' << capacity << ") ";
	ret << "[ ";
	for(int i= 0; i < size; i++)
		ret << arr[i] << " ";
	for(int i= size; i < capacity; i++)
		ret << "- ";
	ret << "]" << endl;
	return ret.str();
}

template<class T>
ostream& operator<<(ostream& os, const ArrayList<T>& list) {
	os << list.toString();
	return os;
}
