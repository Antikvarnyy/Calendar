#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
using namespace std;

bool CheckingDouble(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isdigit(a) && a != ',' && a != '-') {
			b = false;
			break;
		}
	}
	return b;
}
bool CheckingNumbers(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isdigit(a)) {
			b = false;
			break;
		}
	}
	return b;
}
bool CheckingAlpha(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isalpha(a)) {
			b = false;
			break;
		}
	}
	return b;
}
template <typename T>
string toString(T val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) {
		int visok = 0;
		int y_plus;
		int f = 0;
		int mm;
		int yy = y;
		int dd = d;
		do {
			f = 0;
			visok = 0;
			if (m > 12) {
				y_plus = m / 12;
				mm = m % 12;
			}
			if (y % 4 == 0) {
				if (y % 100 == 0) {
					if (y % 400 == 0)
						visok = 1;
				}
			}
			if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
				if (dd > 31) {
					mm++;
					dd -= 31;
					f++;
				}
			}
			else if (mm == 2) {
				if (visok == 1) {
					if (dd > 29) {
						mm++;
						dd -= 29;
						f++;
					}
					else {
						if (dd > 28) {
							mm++;
							dd -= 28;
							f++;
						}
					}
				}
			}
			else {
				if (dd > 30) {
					mm++;
					dd -= 30;
					f++;
				}
			}
		} while (f != 0);
		year = yy + y_plus;
		month = mm;
		day = dd;
	}

	operator int() {
		return year * 365 + month * 30 + day;
	}

	void data(int d) {
		year = d / 365;
		month = d % 365 / 30;
		day = d % 365 % 30;
	}

	void print() {
		cout << year << "." << month << "." << day << "\n";
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	string ss;
	int y, m, d;
	int dtoy;
	do {
		cout << "Введите год: ";
		cin >> ss;
		if (CheckingNumbers(ss))
			y = stoi(ss);
		else
			cout << "Дата введена не корректно!\n";

	} while (!CheckingNumbers(ss));
	do {
		cout << "Введите месяц: ";
		cin >> ss;
		if (CheckingNumbers(ss))
			m = stoi(ss);
		else
			cout << "Дата введена не корректно!\n";

	} while (!CheckingNumbers(ss));
	do {
		cout << "Введите день: ";
		cin >> ss;
		if (CheckingNumbers(ss))
			d = stoi(ss);
		else
			cout << "Дата введена не корректно!\n";

	} while (!CheckingNumbers(ss));
	Date time(y, m, d);
	int days = time;
	cout << "Дата которую Вы ввели: ";
	time.print();
	cout << "Дата которую Вы ввели в днях: " << days << "\n";
	do {
		cout << "Введите количество дней: ";
		cin >> ss;
		if (CheckingNumbers(ss))
			dtoy = stoi(ss);
		else
			cout << "Дата введена не корректно!\n";

	} while (!CheckingNumbers(ss));
	time.data(dtoy);
	cout << "Дата которую Вы ввели: ";
	time.print();
}