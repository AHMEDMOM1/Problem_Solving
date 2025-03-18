//Question link : https://www.hackerrank.com/challenges/gem-stones/problem

#include <iostream>
#include <string>   
#include <vector>

using namespace std;

int inputSize() {
	int size{};
	do {
		cout << "Enter pozitive Num: ";
		while (!(cin >> size)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter Just Number: ";
		}
	} while (size < 0);
	cin.ignore();
	return  size;
}

vector <string> fillStrArray(int size) {
	vector <string> arr(size);
	for (int i{}; i < size; i++) {
		getline(cin, arr.at(i));
	}
	return arr;
}

bool isThereLetter(char isUniqchar, string uniqueLetters) {
	return uniqueLetters.find(isUniqchar) != string::npos;
}

string fillUniqueLetter(string arr) {
	string uniqueLetter{};
	for (size_t i{}; i < arr.size(); i++) {
		if (!isThereLetter(arr.at(i), uniqueLetter)) {
			uniqueLetter.push_back(arr.at(i));
		}
	}
	return uniqueLetter;
}

string deleteNotFoundChar(string str, string uniqueLetter) {
	for (size_t i{}; i < uniqueLetter.size();) {
		if (!isThereLetter(uniqueLetter.at(i), str))
			uniqueLetter.erase(uniqueLetter.begin() + i);
		else
			i++;
	}

	return uniqueLetter;
}


int calcGemStone(vector <string> arr, string uniqueLetter, int size) {
	for (int i{}; i < size; i++) {
		uniqueLetter = deleteNotFoundChar(arr[i], uniqueLetter);
	}
	return uniqueLetter.size();
}


int main() {
	int sizeOfMatrix{ inputSize() };
	vector <string> arr{ fillStrArray(sizeOfMatrix) };

	

	string uniqueLetter{ fillUniqueLetter(arr[0]) };
	cout << calcGemStone(arr, uniqueLetter, sizeOfMatrix);

	return 0;
}
