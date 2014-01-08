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

		V * putAt(const K&, const V&, node *);
	public:
		BinaryTree();
		V * put(const K&, const V&);
		string toString();
};
