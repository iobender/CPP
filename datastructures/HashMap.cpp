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
	map= new entry * [capacity];
	for(unsigned int i= 0; i < capacity; i++)
		map[i]= nullptr;
}

template<class K, class V>
void HashMap<K,V>::put(const K& key, const V& value) {
	unsigned int index= key_hash(key) % capacity;
	if(map[index] == nullptr) {
		map[index] = new entry;
		map[index]->key= key;
		map[index]->value= value;
	} else {
		cout << "Collision for key " << key << " with " << map[index]->key << endl;
		//TODO: fix collision handling
	}
}

template<class K, class V>
string HashMap<K,V>::toString() const {
	stringstream ret;
	ret << "[ ";
	for(int i= 0; i < capacity; i++) {
		if(map[i] == nullptr)
			ret << "- ";
		else {
			ret << '(';
			ret << map[i]->toString();
			ret << ") ";
		}
	}
	ret << "]\n";
	return ret.str();
}

