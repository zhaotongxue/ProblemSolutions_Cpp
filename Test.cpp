// #include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>
using namespace std;
void exchange(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void exchange(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int main()
{

	/*
	vector<int> v;
	for (int i = 5; i < 10; i++) {
		v.push_back(i);
	}
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
		if ((*it) == 7) {
			cout << 7 << endl;
			v.erase(it);
			cout << (it == v.end()) << endl;
			cout << (it > v.end()) << endl;
			cout << (it < v.end()) << endl;
			cout << (it == v.begin()) << endl;
		}
		if ((*it) == 9) {
			cout << 9 << endl;
			v.erase(it);
			cout << (it == v.end()) << endl;
			cout << (it > v.end()) << endl;
			cout << (it < v.end()) << endl;
			cout << (it == v.begin()) << endl;

		} // cout << *it << endl;
		  // cout << *v.begin() << endl;
		  // break;
	}
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	double a = 0;
	cout.fixed;
	cout.precision(2);
	// cout << 3.0 / a << endl;
	cout << (double)0 / 0 << endl;
	cout << (1 ^ 1) << endl;
	cout << (0 ^ 0) << endl;
	cout << (1 ^ 0) << endl;
	for (int a = 0; a <= 1; a++)
		for (int b = 0; b <= 1; b++)
			for (int c = 0; c <= 1; c++)
				cout << a << "^" << b << "^" << c << "=" << (a ^ b ^ c) << endl;
	int coun=25;
	printf("/:%d,%%:%d",coun/10,coun%10);
	*/
	char *str[3] = {"aa", "bb", "cc"};
	for (int i = 0; i < 3; i++) {
		cout << *str[i] << endl;
	}
	return 0;
}
