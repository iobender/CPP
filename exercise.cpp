#include <iostream>
using namespace std;

//goals for 2014
const int miles= 750;
const int crunches= 15000;
const int pushups= 7500;
const int weights= 600;

//year constants
const float days= 365.0f;
const float weeks= 52.0f;
const float months= 12.0f;

int main() {
	bool valid= false;
	string choice;
	do {
		getline(cin, choice);
		if(choice == "run") {
			cout << "You chose run";
		} else {
			cout << "Not valid";
		}
	} while(!valid);

	return 0;
}
