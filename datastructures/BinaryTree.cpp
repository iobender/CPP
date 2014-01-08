/*
 * Matthew Bender
 * Jan 7, 2014
 *
 * Binary search tree implementation in C++
 */
#include<iostream>
#include<sstream>
#include "BinaryTree.hpp"
using namespace std;

template<class K, class V>
BinaryTree<K,V>::BinaryTree() {
	root= nullptr;
}

template<class K, class V>
void BinaryTree<K,V>::add(K key, V value) {
	if(root == nullptr) {
		root= new node;
		root->key= key;
		root->value= value;
	}
}

template<class K, class V>
string BinaryTree<K,V>::toString() {
	stringstream ret;
	if(root == nullptr)
		ret << "-"
	else
		ret << root->toString();
	return ret.str();
}
