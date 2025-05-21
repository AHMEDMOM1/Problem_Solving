// Question Convert Number To Text Like 123 == One Hundred Twenty three

#include <vector>
#include <cmath>
#include <iomanip>

string convEachThreeNum(int eachThreeNum) {
	string Ones[]{ "", "One", "Two", "Three", "Four",
				  "Five", "Six", "Seven", "Eight", "Nine" };


	string Vehicles[]{ "", "Eleven" ,"Twelve", "Thirteen",
					 "Fourteen", "Fifteen", "Sixteen",
					 "Seventeen", "Eighteen", "Nineteen" };

	string Tens[]{ "", "Ten", "Twenty", "Thirty", "Forty",
		  "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

	if (eachThreeNum == 0)return string(0, ' ');
	else if (eachThreeNum < 10)  return Ones[eachThreeNum] + " ";
	else if (eachThreeNum < 20)  return Vehicles[eachThreeNum % 10] + " ";
	else if (eachThreeNum < 100) return Tens[eachThreeNum / 10] + " " + convEachThreeNum(eachThreeNum % 10);
	
	return convEachThreeNum(eachThreeNum / 100) + "Hundred " + convEachThreeNum(eachThreeNum % 100);
}

string getRank(short size) {
	if (size == 1) {
		return "Thousand ";
	}
	else if (size == 2) {
		return "Million ";
	}
	else if (size == 3) return "Billion";

	return string(0, ' ');
}

vector<string> convNumToStr(int num) {
	vector <string> strOfNum{};
	if (num == 0) strOfNum.push_back("Ziro");
	for (short i{}; num > 0; i++) {
		strOfNum.push_back(getRank(i));
		strOfNum.push_back(convEachThreeNum(num % 1000));
		num /= 1000;
	}
	return strOfNum;
}

int main() {
	int num{ 12345645 };
	vector<string> strOfNum{ convNumToStr(num) };
	reverse(strOfNum.begin(), strOfNum.end());

	for (auto& elem : strOfNum) {
		cout << elem;
	}

	return 0;
}
