/*
 * Matthew Bender
 * Jan 7, 2014
 * 
 * LinkedList header file in C++
 */
using namespace std;

template<class T>
class LinkedList {
	private:
		struct node {
			T data;
			node * next;
		};
		node * head;
	public:
		LinkedList();
		bool add(const T&);
		bool add(int, const T&);
		string toString() const;
};

template<class T>
ostream& operator<<(ostream&, const LinkedList<T>&);
