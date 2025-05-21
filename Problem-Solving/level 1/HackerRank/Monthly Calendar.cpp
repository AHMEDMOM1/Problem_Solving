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
using namespace std;

struct Date {
    int year{};
    int month{};
    int day{1};
};

short getNumberOfDaysFromMonth(int month, int year) {
	if (month == 2) return checkIfLeapYear(year) ? 29 : 28;
	else if (month < 7)
		return (month % 2 == 0) ? 30 : 31;
	else
		return (month % 2 == 0) ? 31 : 30;
}

short getDayOfWeek(const Date date) {
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + (12 * a) - 2;
    short dayOfWeek = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return dayOfWeek;
}

bool isLeapYear(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

Date inputBirthday() {
    Date date{};
    cout << "Year: ";
    cin >> date.year;

    cout << "Month: ";
    cin >> date.month;

    return date;
}

void printCalendarHeader(int month) {
    string months[]{
        "", "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };
    string days[]{ "", "Sun", "Mon", "Tue", "Wed",
            "Thu", "Fri", "Sat" };

    cout << setw(18) << setfill('_') << months[month]
         << setw(15) << '_' << setfill(' ') << endl;
    for (int i{1}; i < 8; i++) {
        cout << setw(5) << left << days[i];
    } cout << endl;
}

void printCalendarDays(const Date date) {
    short numDaysInMonth = getDaysInMonth(date.month, date.year);
    short firstDayOfWeek = getDayOfWeek(date);
    short currentDay{1};
    for (short i{}; i < 7; i++) {
        if (i >= firstDayOfWeek) {
            cout << currentDay++;
        }
        else cout << ' ';
        cout << setw(4) << left << ' ';
    } cout << endl;
    // floor for return the last number
    // (numberOfMunth + numOfday) for space in first tabel + number of days in month
    // *. 142 = /7 is column
    // floor((numOfMunth + numOfday)*.142) for compiler know how much row we need
    for (short i{}; i < floor((numDaysInMonth + firstDayOfWeek)*.142); i++) {
        for (short j{}; j < 7; j++) {
            if (currentDay <= numDaysInMonth) {
                cout << setw(5) << left << currentDay++;
            }
        } cout << endl;
    }
}

void displayCalendar() {
    Date date{inputBirthday()};
    printCalendarHeader(date.month);
    printCalendarDays(date);
    cout << setw(33) << setfill('_') << '_';
}

int main() {
    displayCalendar();
    return 0;
}
