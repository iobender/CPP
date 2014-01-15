/*
 * Matthew Bender
 * Jan 15, 2014
 * 
 * HashMap implementation in C++
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "HashMap.hpp"
using namespace std;

template<class K, class V>
HashMap<K,V>::HashMap() {
	capacity= DEFAULT_INITIAL_CAPACITY;
	size= 0;
}
