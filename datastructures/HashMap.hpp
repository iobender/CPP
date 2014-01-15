/*
 * Matthew Bender
 * Jan 15, 2014
 * 
 * Header files for HashMap.cpp
 */
using namespace std;
template<class K, class V>
class HashMap {
	private:
		struct entry {
			K key;
			V value;
			string toString() const {
				stringstream ret;
				ret << key << ":" << value;
				return ret.str();
			}
		};

		const unsigned int DEFAULT_INITIAL_CAPACITY= 7;
		unsigned int capacity;
		unsigned int size;
		entry * * map;
		
	public:
		HashMap();
		//~HashMap();
		string toString() const;
};
