#include <iostream>
using namespace std;

void greet(string name) {
	cout << "Hello, " << name << "!" << endl;
}

int main() {
	string name = " ";

	while(name != "") {
		getline(cin, name);
		greet(name);
	}

	return 0;
}
