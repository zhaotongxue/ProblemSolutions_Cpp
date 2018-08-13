#include <iostream>
using namespace std;
int main() {
	//struct dayInMonth
	//	{
		//int Jan = 31,Mar=31,May=31,Jul=31,Aug=31,Oct=31,Dec=31;
		//int Mar = 30, Jun = 30, Sep = 30, Nov = 30;
		//int Feb = 28;
	// 1 3 5 7 8 10 12
	//4 6 9 11
		const int num1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		const int num2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	//};
	int year, month, day;
	cin >> year >> month >> day;
	int days = 0;
	bool test = false;
	//dayInMonth dd;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		test = true;

	}
	if (test) {
		for (int i = 1; i <= month-1; i++) {
			days += num2[i - 1];
		}
	}
	else {
		for (int i = 1; i <= month-1; i++) {
			days += num1[i - 1];
		}
	}

	days += day;
	cout << year << "年" << month << "月" << day << "日是本年中的第" << days << "天。";
	system("pause");
	return 0;	

}