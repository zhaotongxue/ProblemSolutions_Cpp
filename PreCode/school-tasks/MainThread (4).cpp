#include <iostream>
#include <iomanip>
//#include "CalcClass.h"
using namespace std;
 static double calcMidNum(double intArray[]){
	double temp=0;
	for (int i = 0; i < 6;i++){// sizeof(intArray) / sizeof(double); i++) {
		for (int j = 0; j < i; j++) {
			if (intArray[i] > intArray[j]) {
				temp = intArray[i];
				intArray[i] = intArray[j];
				intArray[j] = temp;
			}
		}
	}
	return (intArray[3] + intArray[2]) / 2;
}
int main() {
	/*
		int scores[2][6];
		cin >> scores[0][0] >> scores[0][1] >> scores[0][2] >> scores[0][3] >> scores[0][4] >> scores[0][5] >> scores[1][0] >> scores[1][1] >> scores[1][2] >> scores[1][3] >> scores[1][4] >> scores[1][5];
		int temp = 0, max = 0, num = 0;
		for (int i = 0; i < 6; i++) {
			temp=scores[0][i] + scores[1][i];
			if (temp > max) {
				max = temp;
				num = i;
			}
		}
		cout << "max=" << max << " num=" << num;
		*/
		/*
		struct weather {
			int month;
			int day;
			int tem;
			double wet;
		};
		weather testWeawther;

		cin >> testWeawther.month >> testWeawther.day >> testWeawther.tem >> testWeawther.wet;
		cout << testWeawther.month << "月" << testWeawther.day << "日温度" << testWeawther.tem << "湿度" << testWeawther.wet;
		*/
	/*
	struct MyStruct

	{
		char* name;
		char* cardNum;
		int score;
	};
	MyStruct s[] = { { "one", "2014140223", 81 }, {"two", "2014140224", 84 }, {"three","2014140225", 88},{ "four", "2014140226", 87}, {"five", "2014140227", 82}, {"six", "2014140228", 89}, {"seven", "2014140229", 85}, {"eight", "2014140230" ,80}}; 
	MyStruct temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i].score > s[j].score) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		cout << s[i].name << " " << s[i].cardNum << " " << s[i].score<<endl;
		//string str = s[i].name + " " + s[i].cardNum + " " + s[i].score + "\n";
		//printf(str);
	}
	*/
	/*
	double intArray[6];
	cin >> intArray[0] >> intArray[1]>> intArray[2]>> intArray[3]>> intArray[4]>> intArray[5];
	//CalcClass cc;
	//double res = cc.calcMidNum(intArray);
	//int res = MainThread::calcMidNum(intArray);
	
	double res = calcMidNum(intArray);
	double temp=0;
	cout << res;
	*/
	int n;
	double defauleS = 100;
	double s=100;
	int temp = 1;
	cin >> n;
	if (n >= 2) {
		s += defauleS;
		for (int i = 2; i < n; i++) {
			//for (int k = 0; i < i-1; k++) {
			//	temp = 2 * temp;
			//}
			//s += defauleS / temp;
			//temp = 1;
			defauleS = defauleS / 2;
			s += defauleS;
		}

	}
	cout << setiosflags(ios::fixed) << setprecision(4) << s;
	system("pause");
}
