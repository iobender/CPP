/*
 * Matthew Bender
 * Jan 6, 2014
 *
 * Header file for ArrayList.cpp
 */
#include <iostream>
using namespace std;

template<class T>
class ArrayList {
	private:
		static const int DEFAULT_INIT_CAPACITY= 4;
		int capacity;
		int size;
		T * arr;
		bool reallocate();
	public:
		ArrayList();
		ArrayList(int);
		int getSize() const;
		T get(int) const;
		bool add(T);
		bool add(int, T);
		T remove(int);
		int find(T) const;
		string toString() const;
};

template<class T>
ostream& operator<<(ostream&, const ArrayList<T>&);
