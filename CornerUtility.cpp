#include "CornerHeader.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// ItemTracker needs to be initialized with a provided file to function
ItemTracker::ItemTracker(const string& file) {
	loadDataFromFile(file);
	saveDataToFile("frequency.dat");
}

// Loads the data from a provided file into the Map that is generated within the Class Object
void ItemTracker::loadDataFromFile(const string& file) {
	ifstream inFile(file);
	string itemName;

	// Checks to make sure the file was actually opened. If not, the program will exit out with exit code 1
	if (!inFile.is_open()) {
		cout << "Could not open file: " << file << ".txt" << endl;
		exit(1);
	}

	// Reads the word from each line in the file
	// If itemName is new to the map, it will initialize it to 0 and then increment it by 1
	// If the itemName already exists, it will increment its count by 1
	while (inFile >> itemName) {
		itemFrequency[itemName] = itemFrequency[itemName] + 1;
	}

	inFile.close();
}

// Saves the data from the Map to a file
void ItemTracker::saveDataToFile(const string& fileName) {
	ofstream outFile(fileName);

	// Loops through the map and writes the product name + its frequency sold into the desired file
	for (auto const& item : itemFrequency) {
		outFile << item.first << " " << item.second << endl;
	}

	outFile.close();
}

// Requires the name of the desired item (not finished)
int ItemTracker::getItemFrequency(const string& itemName) const {
	auto item = itemFrequency.find(itemName);

	if (item != itemFrequency.end()) {
		return item->second; // Returns the frequency if the item is found
	}
	else {
		return 0; // Returns 0 if no item exists with the provided name
	}
}

// Prints the contents of the map which should be populated when the class object was initialized
void ItemTracker::printFrequencyList() const {
	cout << "Item Frequency List" << endl << nCharString(20, '-') << endl;

	for (const auto& itemList : itemFrequency) {
		cout << setw(15) << left << itemList.first << " " << itemList.second << endl;
	}
}

// Prints the frequencies as a text based histogram
void ItemTracker::printHistogram() const {
	cout << "Item Frequency Histogram" << endl << nCharString(25, '-') << endl;

	for (const auto& itemList : itemFrequency) {
		cout << setw(15) << left << itemList.first << " " << nCharString(itemList.second, '*') << endl;
	}
}

// Prints out a list of the items that have been sold
void ItemTracker::printItemNameList() const {
	int itemNum = 1;
	for (const auto& itemList : itemFrequency) {
		cout << itemNum << ". " << itemList.first << endl;
		itemNum++;
	}
}

// Displays a menu for the user to interact with
void displayMenu() {
	cout << "Corner Grocer Item Tracker" << endl << nCharString(30, '-') << endl;
	cout << "1. Get purchase frequency of a specific item" << endl;
	cout << "2. Display purchase frequency of all items" << endl;
	cout << "3. Display purchase frequency of all items as a histogram" << endl;
	cout << "4. Exit Program" << endl;
	cout << "Select an option (1 - 4): ";
}

// Used to easily create menus. Takes in a char and repeats it based on the int provided
string nCharString(int n, char c) {
	return string(n, c);
}