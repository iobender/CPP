#include <iostream>
using namespace std;

template<class T>
class ArrayList {
	private:
		static const int DEFAULT_INIT_CAPACITY= 4;
		unsigned int capacity;
		unsigned int size;
		T * arr;
		bool reallocate();
	public:
		ArrayList();
		ArrayList(unsigned int);
		unsigned int getSize() const;
		unsigned int getCapacity() const;
		bool add(T);
		bool add(int, T);
		string toString() const;
};

template<class T>
ostream& operator<<(ostream&, const ArrayList<T>&);
