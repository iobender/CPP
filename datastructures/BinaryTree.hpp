/*
 * Matthew Bender
 * Jan 7, 2014
 *
 * Header files for binary search tree
 */
using namespace std;

template<class K, class V>
class BinaryTree {
	private:
		struct node {
			K * key;
			V * value;
			node * left, * right;
			string toString() {
				stringstream ret;
				ret << *key << ':' << *value;
				return ret.str();
			}
		};
		node * root;

		void putAt(const K&, const V&, node *);
		bool containsKeyAt(const K&, node *) const;
		V * getAt(const K&, node *) const;
		string toStringAt(node *) const;
	public:
		BinaryTree();
		void put(const K&, const V&);
		bool containsKey(const K&) const;
		V * get(const K&) const;
		string toString() const;
};

template<class K, class V>
ostream& operator<<(ostream&, const BinaryTree<K,V>&);
