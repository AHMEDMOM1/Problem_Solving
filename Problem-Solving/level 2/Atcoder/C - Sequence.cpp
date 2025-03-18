// Qustion Link: https://atcoder.jp/contests/arc072/tasks/arc072_a

vector <double> inputEqualNum() {
	int size{};
	do {
	cout << "How much element: ";
	cin >> size;

	} while (size < 1 || size > pow(10, 5));

	vector <double> equalNum(size + 1);
	for (int i{ 1 }; i <= size; i++) {
		do {
			cout << "[" << i << "]: ";
			cin >> equalNum.at(i);
		} while (equalNum.at(i) > pow(10, 9));
	}

	return equalNum;
}
void checkSign(int sum, vector<string>& signOfTotal) {

	if (sum > 0) {
		signOfTotal.push_back("Positive");
	}
	else if(sum < 0) {
		signOfTotal.push_back("Negative");
	}
	else {
		signOfTotal.push_back("Zero");
	}

}

double calcMinTotalOfEquation(vector <double>& element) {
	int TotalOfEquation{};
	int sum{};

	vector <string> signOfTotal{ "Zero" };

	for (size_t i{ 1 }; i < element.size(); i++) {
		sum += element.at(i);
		checkSign(sum, signOfTotal);
		if (signOfTotal.at(i) == "Zero") {
			element.at(i) > 0 ? element.at(i)++,sum++ : element.at(i)--,sum--;
			TotalOfEquation++;
			checkSign(sum, signOfTotal);
		}
		else if (signOfTotal.at(i) == signOfTotal.at(i - 1)) {
			TotalOfEquation += abs(sum) + 1;
			sum -= element.at(i);
			element.at(i) = (sum > 0 ? (sum + 1) : (sum - 1)) * -1;
			sum += element.at(i);
			signOfTotal.at(i) = (sum > 0 ? "Positive" : "Negative");

		}
	}

	return TotalOfEquation;
}

void printEqual(short total, vector <double> element) {
	cout << "{ ";
	for (size_t i{ 1 }; i < element.size(); i++) {
		cout << element.at(i) << " ";
		if (i < element.size() - 1) {
			cout << ",";
		}
	}cout << "}" << endl;
	cout << "Total is: " << total;
}

int main() {
	vector <double> element{ inputEqualNum() };
	double total{ calcMinTotalOfEquation(element) };
	printEqual(total, element);

	return 0;
}
