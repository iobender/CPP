#include <iostream>
using namespace std;

template<class T>
class ArrayList {
	private:
		static const int DEFAULT_INIT_CAPACITY= 4;
		unsigned int capacity;
		unsigned int size;
	public:
		ArrayList();
		ArrayList(unsigned int);
		unsigned int getSize();
		unsigned int getCapacity();
};
