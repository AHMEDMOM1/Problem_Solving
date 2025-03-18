/*
Problem Statement

There is a collection of rocks where each rock has various minerals embedded in it. Each type of mineral is designated by a lowercase letter in the range ascii[a-z].
There may be multiple occurrences of a mineral in a rock. A mineral is called a gemstone if it occurs at least once in each of the rocks in the collection.
Given a list of minerals embedded in each of the rocks, display the number of types of gemstones in the collection.

Example

plaintext
arr = ['abc', 'abc', 'bc']
The minerals `b` and `c` appear in each rock, so there are 2 gemstones.
Function Description

Complete the gemstones function in the editor below.

gemstones** has the following parameter(s):
 string arr[n]: an array of strings

Returns 
 int: the number of gemstones found

Input Format

The first line consists of an integer n, the size of arr.
Each of the next n lines contains a string arr[i] where each letter represents an occurrence of a mineral in the current rock.

Constraints
- 1 ≤ n ≤ 100
- 1 ≤ | arr[i] | ≤ 100
- Each composition arr[i] consists of only lower-case Latin letters ('a'-'z').

Sample Input
plaintext

STDIN        Function
-----        --------
3            arr[] size n = 3
abcdde       arr = ['abcdde', 'baccd', 'eeabg']
baccd
eeabg

Sample Output
plaintext
2

Explanation
Only `a` and `b` occur in every rock.
-----------------------------------------------------
*/

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
}//Question link : https://www.hackerrank.com/challenges/gem-stones/problem
