#include "sort.h"
#include <iostream>
#include <ctime>

int main() {

	/*
	string s1 = "engineers";
	cout << s1 << " -> " << sortByFreq(s1) << endl; // correct answer: girsnneee

	string s2 = "engineering";
	cout << s2 << " -> " << sortByFreq(s2) << endl; // correct answer: rggiieeennn
	*/

	string s;
	while (1) {
		cout << "Input string: ";
		cin >> s;
		clock_t startTime = clock();
		string outs = sortByFreq(s);
		double elapsedTime = (clock() - startTime) / (double)CLOCKS_PER_SEC;
		cout << "Output string: " << sortByFreq(s) << endl;
		cout << "Time taken: " << elapsedTime << " sec" << endl << endl;

	}

	return 0;
}