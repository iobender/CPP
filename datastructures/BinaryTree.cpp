/*
 * Matthew Bender
 * Jan 7, 2014
 *
 * Binary search tree implementation in C++
 */
#include <iostream>
#include <sstream>
#include "BinaryTree.hpp"
using namespace std;

template<class K, class V>
BinaryTree<K,V>::BinaryTree() {
	root= nullptr;
}

template<class K, class V>
V * BinaryTree<K,V>::put(const K& key, const V& value) {
	if(root == nullptr) {
		root= new node;
		root->left= root->right= nullptr;
		root->key= new K (key);
		root->value= new V (value);
		return nullptr;
	} else {
		return putAt(key, value, root);
	}
}

template<class K, class V>
V * BinaryTree<K,V>::putAt(const K& key, const V& value, node * curr) {

}

template<class K, class V>
string BinaryTree<K,V>::toString() {
	stringstream ret;
	if(root == nullptr)
		ret << "-";
	else
		ret << root->toString();
	return ret.str();
}
