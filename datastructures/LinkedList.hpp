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
		int size;
	public:
		LinkedList();
		int getSize() const;
		T get(int) const;
		bool add(const T&);
		bool add(int, const T&);
		T set(int, const T&);
		T remove(int);
		bool removeElt(const T&);
		void clear();
		int find(const T& elt) const;
		T * toArr() const;
		string toString() const;
};

template<class T>
ostream& operator<<(ostream&, const LinkedList<T>&);
