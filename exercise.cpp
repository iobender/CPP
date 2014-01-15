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

float calcWeekFraction(int week) {
	return (float) (5 + 7*(week - 1))/days;
}

float calcMonthFraction(int month) {
	return (float) month/months;
}

void printGoals(float fraction) {
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

	float fraction;
	if(week) {
		cout << "Goals for week " << choice << ":\n";
		fraction= calcWeekFraction(choice);
	} else {
		cout << "Goals for month " << choice << ":\n";
		fraction= calcMonthFraction(choice);
	}

	printGoals(fraction);	

	return 0;
}
