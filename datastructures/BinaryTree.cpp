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
void BinaryTree<K,V>::put(const K& key, const V& value) {
	if(root == nullptr) {
		root= new node;
		root->left= root->right= nullptr;
		root->key= new K (key);
		root->value= new V (value);
	} else {
		putAt(key, value, root);
	}
}

template<class K, class V>
void BinaryTree<K,V>::putAt(const K& key, const V& value, node * curr) {
	if(key == *(curr->key)) {
		V * old= curr-> value;
		curr->value= new V (value);
		delete old;
	} else if (key < *(curr->key)) {
		if(curr->left == nullptr) {
			curr->left= new node;
			curr->left->left= curr->left->right= nullptr;
			curr->left->key= new K (key);
			curr->left->value= new V (value);
		} else 
			putAt(key, value, curr->left);
	} else {
		if(curr->right == nullptr) {
			curr->right= new node;
			curr->right->left= curr->right->right= nullptr;
			curr->right->key= new K (key);
			curr->right->value= new V (value);
		} else
			putAt(key, value, curr->right);
	}
}

template<class K, class V>
bool BinaryTree<K,V>::containsKey(const K& key) const {
	return containsKeyAt(key, root);
}

template<class K, class V>
bool BinaryTree<K,V>::containsKeyAt(const K& key, node * curr) const {
	if(curr == nullptr)
		return false;
	if(key == *(curr->key))
		return true;
	if(key < *(curr->key))
		return containsKeyAt(key, curr->left);
	else
		return containsKeyAt(key, curr->right);
}

template<class K, class V>
V * BinaryTree<K,V>::get(const K& key) const {
	return getAt(key, root);
}

template<class K, class V>
V * BinaryTree<K,V>::getAt(const K& key, node * curr) const {
	if(curr == nullptr)
		return nullptr;
	if(key == *(curr->key))
		return curr->value;
	else if(key < *(curr->key))
		return getAt(key, curr->left);
	else 
		return getAt(key, curr->right);
}

template<class K, class V>
string BinaryTree<K,V>::toString() const {
	stringstream ret;
	ret << "[ ";
	ret << toStringAt(root);
	ret << "]\n";
	return ret.str();
}

template<class K, class V>
string BinaryTree<K,V>::toStringAt(node * curr) const {
	if(curr == nullptr)
		return "";
	stringstream ret;
	ret << toStringAt(curr->left);
	ret << *(curr->key) << ":" << *(curr->value) << " ";
	ret << toStringAt(curr->right);
	return ret.str();
}

template<class K, class V>
ostream& operator<<(ostream& os, const BinaryTree<K,V>& tree) {
	os << tree.toString();
	return os;
}
