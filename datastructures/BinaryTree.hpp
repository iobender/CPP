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
			~node() {
				delete key;
				delete value;
			}
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
		node * removeAt(const K&, node *);
		node * minNode(node *) const;
		node * maxNode(node *) const;
		void clearAt(node *);
		string toStringAt(node *, int) const;
	public:
		BinaryTree();
		void put(const K&, const V&);
		bool containsKey(const K&) const;
		V * get(const K&) const;
		void remove(const K&);
		K min() const;
		K max() const;
		void clear();
		string toString() const;
};

template<class K, class V>
ostream& operator<<(ostream&, const BinaryTree<K,V>&);
