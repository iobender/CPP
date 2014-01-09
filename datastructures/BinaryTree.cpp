/*
 * Matthew Bender
 * Jan 7, 2014
 *
 * Binary search tree implementation in C++
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "BinaryTree.hpp"
using namespace std;

template<class K, class V>
BinaryTree<K,V>::BinaryTree() {
	root= nullptr;
}

template<class K, class V>
BinaryTree<K,V>::~BinaryTree() {
	clear();
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
void BinaryTree<K,V>::remove(const K& key) {
	root= removeAt(key, root);
}

template<class K, class V>
struct BinaryTree<K,V>::node * BinaryTree<K,V>::removeAt(const K& key, node * curr) {
	if(curr == nullptr)
		return nullptr;
	if(key == *(curr->key)) {
		if(curr->left == nullptr && curr->right == nullptr) {
			delete curr;
			return nullptr;
		} else if(curr->left == nullptr && curr->right != nullptr) {
			node * next= curr->right;
			delete curr;
			return next;
		} else if(curr->left != nullptr && curr->right == nullptr) {
			node * next= curr->left;
			delete curr;
			return next;
		} else {
			node * leftMax= maxNode(curr->left);
			*(curr->key)= *(leftMax->key);
			*(curr->value)= *(leftMax->value);
			removeAt(*(leftMax->key), curr->left);
			return curr;
		}
	} else if(key < *(curr->key)) {
		curr->left= removeAt(key, curr->left);
		return curr;
	} else {
		curr->right= removeAt(key, curr->right);
		return curr;
	}
}

template<class K, class V>
K BinaryTree<K,V>::min() const {
	if(root == nullptr)
		throw "Error in BinaryTree<K,V>::min(): tree is empty";
	return *(minNode(root)->key);
}

template<class K, class V>
K BinaryTree<K,V>::max() const {
	if(root == nullptr)
		throw "Error in BinaryTree<K,V>::max(): tree is empty";
	return *(maxNode(root)->key);
}

template<class K, class V>
struct BinaryTree<K,V>::node * BinaryTree<K,V>::minNode(node * curr) const {
	if(curr->left == nullptr)
		return curr;
	else
		return minNode(curr->left);
}

template<class K, class V>
struct BinaryTree<K,V>::node * BinaryTree<K,V>::maxNode(node * curr) const {
	if(curr->right == nullptr)
		return curr;
	else
		return maxNode(curr->right);
}

template<class K, class V>
void BinaryTree<K,V>::clear() {
	clearAt(root);
	root= nullptr;
}

template<class K, class V>
void BinaryTree<K,V>::clearAt(node * curr) {
	if(curr != nullptr) {
		clearAt(curr->left);
		clearAt(curr->right);
		delete curr;
	}
}

template<class K, class V>
bool BinaryTree<K,V>::isEmpty() const {
	return root == nullptr;
}

template<class K, class V>
string BinaryTree<K,V>::toString() const {
	stringstream ret;
	ret << "[ ";
	ret << toStringAt(root, 1);
	ret << "]\n";
	return ret.str();
}

template<class K, class V>
string BinaryTree<K,V>::toStringAt(node * curr, int level) const {
	if(curr == nullptr)
		return "";
	stringstream ret;
	ret << toStringAt(curr->left, level+1);
	ret << *(curr->key) << "->" << *(curr->value) << ":(" << level << ") ";
	ret << toStringAt(curr->right, level+1);
	return ret.str();
}

template<class K, class V>
ostream& operator<<(ostream& os, const BinaryTree<K,V>& tree) {
	os << tree.toString();
	return os;
}
