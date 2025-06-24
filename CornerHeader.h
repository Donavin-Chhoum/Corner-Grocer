#ifndef CORNERHEADER_H
#define CORNERHEADER_H

#include <iostream>
#include <map>

using namespace std;

class ItemTracker {
	public:
		ItemTracker(const string& file);
		int getItemFrequency(const string& item) const;
		void printItemNameList() const;
		void printFrequencyList() const;
		void printHistogram() const;

	private:
		map<string, int> itemFrequency;
		void loadDataFromFile(const string& file);
		void saveDataToFile(const string& file);

};

void displayMenu();
string nCharString(int n, char c);

#endif
