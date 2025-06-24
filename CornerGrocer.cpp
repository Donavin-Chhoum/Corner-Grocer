#include "CornerHeader.h"
#include <iostream>

using namespace std;

int main() {
	ItemTracker list("Grocery List.txt"); // Initializes a ItemTracker object using a file with the provided name

	int choice = 0;
	string itemName;

	while (true) {
		displayMenu();
		cin >> choice;
		cout << endl;

		// Checks to make sure that the user input is an integer
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input." << endl;
			continue;
		}

		// Takes user input to determine what code to execute
		switch (choice) {
			case 1:
				cout << "Items Sold" << endl << nCharString(10 , '-') << endl;
				list.printItemNameList();

				cout << "Enter item name (case sensitive): ";

				cin >> itemName;
				cout << itemName << " were purchased " << list.getItemFrequency(itemName) << " times." << endl;
				cout << endl;
				break;

			case 2:
				list.printFrequencyList(); // Prints the purchase frequency as integers
				cout << endl;
				break;

			case 3:
				list.printHistogram(); // Prints purchase frequency as a text-based histogram
				cout << endl;
				break;

			case 4:
				cout << "Exiting Program." << endl;
				return 0;

			default:
				cout << "Invalid Input." << endl << endl;
		}
	}

	return 0;
}