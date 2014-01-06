#include <iostream>
#include "ArrayList.hpp"
using namespace std;

template<class T>
ArrayList<T>::ArrayList() {
	ArrayList<T>::capacity= ArrayList<T>::DEFAULT_INIT_CAPACITY;
}

template<class T>
ArrayList<T>::ArrayList(unsigned int init_capacity) {
	ArrayList<T>::capacity= init_capacity;
}

template<class T>
unsigned int ArrayList<T>::getSize() { 
	return ArrayList::size; 
}

template<class T>
unsigned int ArrayList<T>::getCapacity() {
	return ArrayList<T>::capacity;
}
