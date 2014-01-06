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
	double fraction= (double) (5 + 7*(week - 1))/days;
	
	cout << "Goals for week " << week << ":";
	cout << "\nMiles ran: " << fraction*miles;
	cout << "\nCrunches:  " << fraction*crunches;
	cout << "\nPushups:   " << fraction*pushups;
	cout << "\nWeights:   " << fraction*weights;
}

void calcMonth(int month) {
	double fraction= (double) month/months;

	cout << "Goals for month " << month << ":\n";
	cout << "\nMiles ran: " << fraction*miles;
	cout << "\nCrunches:  " << fraction*crunches;
	cout << "\nPushups:   " << fraction*pushups;
	cout << "\nWeights:   " << fraction*weights;
}

int main() {
	int choice;
	string entry;
	bool week= true;
	cout << "Enter a week: (or type month): ";
	getline(cin, entry);
	if(entry == "month" || entry == "m") {
		week= false;
		cout << "Enter a month: ";
		getline(cin, entry);
	}
	stringstream(entry) >> choice;
	cout << endl;

	if(week)
		calcWeek(choice);
	else
		calcMonth(choice);

	return 0;
}
