/*
 * Matthew Bender
 * Jan 6, 2014
 *
 * Implementation of ArrayList in C++
 * Provides a growable array, similar to the vector class. 
 * Allows for constant access of elements, as well as 
 * easy addition/removal/indexing elements.
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ArrayList.hpp" //Header file for ArrayList
using namespace std;

/*
 * Default constructor
 * Initializes capacity of ArrayList to be default value,
 * size to be 0, and initializes data array.
 */
template<class T>
ArrayList<T>::ArrayList() {
	capacity= DEFAULT_INIT_CAPACITY;
	size= 0;
	arr= new T [capacity];
}

/*
 * Constructor that takes the initial capacity as parameter
 * Initializes size to be 0 and data array to the initial capacity
 */
template<class T>
ArrayList<T>::ArrayList(int init_capacity) {
	capacity= init_capacity;
	size= 0;
	arr= new T [capacity];
}

/*
 * Returns the number of elements in the list. 
 * Note this is NOT the current capacity of the list.
 */
template<class T>
int ArrayList<T>::getSize() const { 
	return size; 
}

/*
 * Returns the element at the given index.
 * Throws an exception if the index is out of bounds
 */
template<class T>
T ArrayList<T>::get(int index) const {
	if(index < 0 || index >= size)
		throw out_of_range("Index out of bounds in ArrayList<T>::get");
	else
		return arr[index];
}

/*
 * Adds the given element to the end of the list.
 * If needed, more space is allocated.
 */
template<class T>
bool ArrayList<T>::add(T elt) {
	if(size == capacity)
		reallocate();
	arr[size++]= elt;
	return true;
}

/*
 * Adds the given element to the given index,
 * shifting right elements to the right.
 * If needed, more space is allocated. 
 * If the given index is not valid, an exception is thrown.
 */
template<class T>
bool ArrayList<T>::add(int index, T elt) {
	if(index < 0 || index > size)
		throw out_of_range("Index out of bounds in ArrayList<T>::add");
	if(size == capacity)
		reallocate();
	for(int i= size; i > index; i--) 
		arr[i]= arr[i-1];
	arr[index]= elt;
	size++;
	return true;
}

/*
 * Removes the element at the given index, 
 * shifting left elements to the right.
 * If the given index is not valid, an exception is thrown. 
 */
template<class T>
T ArrayList<T>::remove(int index) {
	if(index < 0 || index >= size)
		throw out_of_range("Index out of bounds in ArrayList<T>::remove");
	for(int i= index; i+1 < size; i++) 
		arr[i]= arr[i+1];
	size--;
}

/*
 * Returns the index of the given element, 
 * or -1 if the element is not found. 
 * Checks for equality with the == operator.
 */
template<class T>
int ArrayList<T>::find(T elt) const {
	for(int i= 0; i < size; i++) {
		if(arr[i] == elt)
			return i;
	}
	return -1;
}

/*
 * Reallocates more space when the currently allocated array is full.
 * Creates a new array of twice the previous capacity,
 * then copies over the data to it, and makes this the new array. 
 */
template<class T>
bool ArrayList<T>::reallocate() {
	capacity *= 2;
	T * newarr= new T [capacity];
	for(int i= 0; i < size; i++)
		newarr[i]= arr[i];
	delete [] arr;
	arr= newarr;
}

/*
 * Returns a string representation of the ArrayList.
 * Displays the size, capacity, and elements. 
 */
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

/*
 * Overloads the << operator, returning the same as toString()
 */
template<class T>
ostream& operator<<(ostream& os, const ArrayList<T>& list) {
	os << list.toString();
	return os;
}
