#include <iostream>
#include <iomanip>
using namespace std;
void Func(int *A, int nSize) {
	int temp = 0,realCount=nSize;
	int zeroCount = 0;
	for (int i = 0; i < nSize; i++) {
		if (A[i] == 0) {
			temp = A[nSize - 1];
			A[i] = temp;
			A[nSize - 1] = 0;
			if (nSize - i == 1) {
				i--;
			}
			nSize--;
		}
		for (int j = 0; j < i; j++) {
			if (A[i] < A[j]) {
				temp = A[i];
				for (int t = i; t > j; t--) {
					A[t] = A[t - 1];
				}
				A[j] = temp;
				//A[i] = A[j];
				//A[j] = temp;
			}
		}
	}
	for (int i = 0; i < realCount-1; i++) {
		cout << A[i]<<" ";
	}
	cout << A[realCount - 1];
}
void get_average(double* arr,int n) {
	double max = arr[0], min = arr[0],sum=0;
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
		sum += arr[i];
	}
	double average = (sum - max - min) / (n - 2);
	cout << setiosflags(ios::fixed) << setprecision(2) << average;

}
int tmain() {
	//int totalNum;
	//cin >> totalNum;
	//int *A = new int[totalNum];
	//for (int i = 0; i < totalNum; i++) {
	//	A[i] = 0;
	//	cin >> A[i];
	//}
	//Func(A, totalNum);
	/*
	int* p = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
	}
	int min=p[0], max=p[0];
	for (int i = 0; i < 5; i++) {
		if (min > p[i]) {
			min = p[i];
		}
		if (max < p[i]) {
			max=p[i];
		}
	}
	cout << min << " " << max;

	char* chars=new char[24];
	for (int i = 0; i < 24; i++) {
		chars[i] = 0;
	}
	cin.getline(chars, 24);
	for (int i = 23; i >= 0; i--) {
		if (chars[i] != 0) {
			cout << chars[i];
		}
	}

	int temp = 0,high,mid;
	for (int i = 2; i < 1000; i++) {
		temp = i;
		high = temp / 100;
		temp = temp % 100;
		mid = temp / 10;
		temp = temp % 10;
		if (high*high*high+ mid*mid*mid+ temp*temp*temp == i) {
			cout << i << " ";
		}

	}
	*/
	int firNum;
	cin >> firNum;
	double* fir = new double[firNum];
	for (int i = 0; i < firNum; i++) {
		cin >> fir[i];
	}
	int secNum;
	cin >> secNum;
	double* sec = new double[secNum];
	for (int i = 0; i < secNum; i++) {
		cin >> sec[i];
	}
	get_average(fir, firNum);
	cout << endl;
	get_average(sec, secNum);
	system("pause");
	return 0;
}