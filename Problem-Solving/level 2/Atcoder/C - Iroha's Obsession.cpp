// Link of question : https://atcoder.jp/contests/arc058/tasks/arc058_a

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSum(vector <short> total) {
	if (total.at(0) == 0) {
		for (unsigned int i{1}; i < total.size(); i++) {
			cout << total.at(i);
		}

	}
	else {
		for (unsigned short sh : total) {
			cout << sh;
		}
	}
}

vector <short> totaMoney(int total, vector <short>& numbers) {
	int sum{}, totalSize{}, num{};
	bool ok{}, lastNumber{};
	for (unsigned int sz{ 1 }; sz <= total;sz *= 10) { // 1999
		++totalSize;
		
	}
	vector <short> tot(totalSize + 1);
	vector <short>::iterator start{ numbers.begin() };
	

	for (int i = totalSize; i >= 0; i--) {
		num = total % 10;
		tot.at(i) = num;
		total /= 10;
	}

	vector<short>::iterator totStart{ tot.begin() + 1 };

	
	for (; totStart < tot.end();) {
		while (start < numbers.end()) {
			if (*totStart == *start) { //  0000 9
				ok = true;
				totStart++;
				break;
			}
			else {
				start++;
			}
		}
		if (!ok) {
			if (*totStart == 9) {
				++(*(totStart - 1));
				totStart--;
			}
			else {
				++(*totStart);
			}
			lastNumber = true;
		}
		else if(lastNumber){
			while (totStart < tot.end()) {
				*(totStart) = numbers.front();
				totStart++;
			}
		}
		start = numbers.begin();
		ok = false;
	}

	return tot;
}

vector <short>  checkNotHeatNums(size_t& total, size_t& K, vector <short>& inptVc) {
	vector <short> numbers{ 0,1,2,3,4,5,6,7,8,9 };


	for (unsigned int i{}; i < inptVc.size(); i++) {
		if (i == inptVc.size() - 1 && inptVc.at(i) == 0) { numbers.erase(numbers.begin()); }

		else {
			numbers.erase(numbers.begin() + (inptVc.at(i) - i));
		}
	}



	return totaMoney(total,numbers);
}

vector <short> inputNumbers() {
	size_t total{}, K{};
	
	do{
	    cout << "How much will you pay (Choose a number smaller than 10000) : ";
	    cin >> total;
	} while(total > 10000);

	do{
	    cout << "How many numbers do you hate: ";
	    cin >> K;
	} while(K > 9);
	vector <short> sht(K);

	for (unsigned int i{}; i < sht.size(); i++) {
		do{
		cout << "The " << i + 1 << ". Number is: ";
		cin >> sht.at(i);
		} while( sht.at(i) > 9 );
	}
	sort(sht.begin(), sht.end());
	return checkNotHeatNums(total, K, sht);
}

int main() {
	printSum(inputNumbers());
	
	return 0;
}
