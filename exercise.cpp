#include <iostream>
#include <sstream>
using namespace std;

//goals for 2014
const int miles= 750;
const int crunches= 15000;
const int pushups= 7500;
const int weights= 600;

//year constants
const int days= 365;
const int weeks= 52;
const int months= 12;

void calcWeek(int week) {
	cout << "Calculating stats for week " << week;
}

void calcMonth(int month) {
	cout << "Calculating stats for month " << month;
}

int main() {
	int choice;
	string entry;
	bool week= true;
	cout << "Enter a week: (or enter month): ";
	getline(cin, entry);
	if(entry == "month" || entry == "m") {
		week= false;
		cout << "Enter a month: ";
		getline(cin, entry);
	}
	stringstream(entry) >> choice;

	if(week)
		calcWeek(choice);
	else
		calcMonth(choice);

	return 0;
}
