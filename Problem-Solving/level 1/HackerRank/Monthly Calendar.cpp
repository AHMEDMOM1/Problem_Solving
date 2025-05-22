// Write a program that prints the monthly calendar like this:
/*
______________Marc_______________
sun  Mon  Tue  Wed  Thu  Fri  Sat
                              1
2    3    4    5    6    7    8
9    10   11   12   13   14   15
16   17   18   19   20   21   22
23   24   25   26   27   28   29
30   31
_________________________________
*/

//######################################
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Data {
	short Day{1};
	short Month{};
	short Year{};
};

bool checkIfLeapYear(int year) {
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

short getNumberOfDaysInMonth(short month, short year) {
	if (month == 2) return checkIfLeapYear(year) ? 29 : 28;
	else if (month < 7)
		return (month % 2 == 0) ? 30 : 31;
	else
		return (month % 2 == 0) ? 31 : 30;
}

Data fillDataInfo() {
	Data data{};
	cout << "Year: ";
	cin >> data.Year;

	cout << "Month: ";
	cin >> data.Month;

	return data;
}

short getDayNum(Data data) {
	int a = (14 - data.Month) / 12;
	int y = data.Year - a;
	int m = data.Month + (12 * a) - 2;
	short d = (data.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string getMonthName(short monthNumber) {
	string Month[]{
		"","jan", "Feb", "Marc", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Cot", "Nov", "Dec"
	};
	return Month[monthNumber];
}

void showHeaderCalender(short monthNum) {
	string Days[]{ "", "Sun", "Mon", "Tue", "Wed",
			"Thu", "Fri", "Sat" };
	cout << setw(18) << setfill('_') << right << getMonthName(monthNum)
	     << setw(15) << '_' << setfill(' ') << endl;
	for (short i{ 1 }; i < 8; i++) {
		cout << setw(5) << left << Days[i];
	}cout << endl;
}

void showBodyCalender(short dayNum, Data data) {
	short monthNum = getNumberOfDaysInMonth(data.Month, data.Year);
	short counter{ 1 };
	for (short i{ 0 }; i < 7; i++) { // i && monthnum started from 0
		if (i >= dayNum)
			cout << setw(5) << left << counter++;
		else
			cout << setw(5) << ' ';
	}cout << endl;
	short row = ceil((monthNum - counter) * .142);
	short column{ 7 };
	for (short i{}; i < row; i++) {
		for (short j{}; j < column; j++) {
			if (counter <= monthNum)
				cout << setw(5) << left << counter++;
			else
				cout << setw(5) << ' ';
		}cout << endl;
	}
}

void showCalenderList() {
	Data data{ fillDataInfo() };
	short dayNum = getDayNum(data);
	showHeaderCalender(data.Month);
	showBodyCalender(dayNum, data);
	cout << setw(33) << setfill('_') << '_' << setfill(' ') << endl;
}

int main() {
	showCalenderList();
	return 0;
}
