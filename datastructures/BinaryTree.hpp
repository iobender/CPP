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
			K key;
			V value;
			node * left, * right;
			string toString() {
				stringstream ret;
				ret << key << ':' << value;
				return ret.str();
			}
		};
		node * root;
	public:
		BinaryTree();
		void add(K,V);
		string toString();
};
