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
	*/
	double a = 0;
	cout.fixed;
	cout.precision(2);
	// cout << 3.0 / a << endl;
	cout << (double)0 / 0 << endl;
	return 0;
}
