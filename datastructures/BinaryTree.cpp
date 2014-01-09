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

/*
 * Default constructor. 
 * Makes sure root is null.
 */
template<class K, class V>
BinaryTree<K,V>::BinaryTree() {
	root= nullptr;
}

/*
 * Destructor
 * clears all nodes and their memory.
 */
template<class K, class V>
BinaryTree<K,V>::~BinaryTree() {
	clear();
}

/*
 * Puts a key-value pair in the map. Replaces old value
 * if key already exists.
 * Calls helper function for use of recursion.
 */
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

/*
 * Helper function for put().
 */
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

/*
 * Returns true if the map contains the given key, else false.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
bool BinaryTree<K,V>::containsKey(const K& key) const {
	return containsKeyAt(key, root);
}

/*
 * Helper function for containsKey().
 */
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

/*
 * Returns a pointer to the value for the given key.
 * Returns nullptr if the key is not in the map.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
V * BinaryTree<K,V>::get(const K& key) const {
	return getAt(key, root);
}

/*
 * Helper function for get().
 */
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

/*
 * Removes the given key and its value from the map.
 * Does nothing if the key is not in the map.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
void BinaryTree<K,V>::remove(const K& key) {
	root= removeAt(key, root);
}

/*
 * Helper function for remove().
 */
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

/*
 * Returns the minimum key in the map.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
K BinaryTree<K,V>::min() const {
	if(root == nullptr)
		throw "Error in BinaryTree<K,V>::min(): tree is empty";
	return *(minNode(root)->key);
}

/*
 * Returns the maximum key in the map.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
K BinaryTree<K,V>::max() const {
	if(root == nullptr)
		throw "Error in BinaryTree<K,V>::max(): tree is empty";
	return *(maxNode(root)->key);
}

/*
 * Helper function for min().
 */
template<class K, class V>
struct BinaryTree<K,V>::node * BinaryTree<K,V>::minNode(node * curr) const {
	if(curr->left == nullptr)
		return curr;
	else
		return minNode(curr->left);
}

/*
 * Helper function for max().
 */
template<class K, class V>
struct BinaryTree<K,V>::node * BinaryTree<K,V>::maxNode(node * curr) const {
	if(curr->right == nullptr)
		return curr;
	else
		return maxNode(curr->right);
}

/*
 * Removes all nodes from the list.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
void BinaryTree<K,V>::clear() {
	clearAt(root);
	root= nullptr;
}

/*
 * Helper function for clear().
 */
template<class K, class V>
void BinaryTree<K,V>::clearAt(node * curr) {
	if(curr != nullptr) {
		clearAt(curr->left);
		clearAt(curr->right);
		delete curr;
	}
}

/*
 * Returns if the tree is empty.
 */
template<class K, class V>
bool BinaryTree<K,V>::isEmpty() const {
	return root == nullptr;
}

/*
 * Returns a string representation of this map,
 * including what level of the tree each node is on.
 * Calls helper function for use of recursion.
 */
template<class K, class V>
string BinaryTree<K,V>::toString() const {
	stringstream ret;
	ret << "[ ";
	ret << toStringAt(root, 1);
	ret << "]\n";
	return ret.str();
}

/*
 * Helper function for toString().
 */
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

/*
 * Overloads the ostream << operator for the BinaryTree class
 */
template<class K, class V>
ostream& operator<<(ostream& os, const BinaryTree<K,V>& tree) {
	os << tree.toString();
	return os;
}
