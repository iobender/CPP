/*
 * Matthew Bender
 * Jan 6, 2014
 *
 * Header file for ArrayList.cpp
 */
using namespace std;

template<class T>
class ArrayList {
	private:
		static const int DEFAULT_CAPACITY= 4;
		int capacity;
		int size;
		T * arr;
		
		bool reallocate(int);
	public:
		ArrayList();
		ArrayList(int);
		int getSize() const;
		T get(int) const;
		bool add(const T&);
		bool add(int, const T&);
		T set(int, const T&);
		T remove(int);
		bool removeElt(const T&);
		void clear();
		int find(T) const;
		T * toArr() const;
		string toString() const;
};

template<class T>
ostream& operator<<(ostream&, const ArrayList<T>&);
