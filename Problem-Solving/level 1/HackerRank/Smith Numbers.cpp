// Question link :: https://www.hackerrank.com/challenges/identify-smith-numbers/problem

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int isPrime(int devid, int num) {
    for (int i{devid}; i < sqrt(num); i++) {
        if (num % i == 0) {
            return devid;
        }
    }
    return num;
}

short sumDigit(int devid) {
    short sum{};
    while (devid > 0) {
        sum += devid % 10;
        devid /= 10;
    }

    return sum;
}

short sumNumber(int num) {
    int devid{ 2 };
    short sum{};
    while (num > 1) {
        if (num % devid == 0) {
            sum += sumDigit(devid);
            num /= devid;
        }
        else {
            devid++;
            devid = isPrime(devid, num);
        }
    }
    
    return sum;
}

bool isEqual(short sumDevid, short sumDigit) {
    return sumDevid == sumDigit;
}

int inputNum() {
    int num{};
    
    while (!(cin >> num) || (num < 0 || num >= numeric_limits<int>::max())) {
    	cin.clear();
    	cin.ignore();
    }

    return num;
}

int main() {
    int num{ inputNum() };
    cout << isEqual(sumNumber(num), sumDigit(num));

    return 0;
}
