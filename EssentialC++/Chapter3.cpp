#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
vector<int> less_than_110(const vector<int> &vec)
{
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ix++) {
		if (vec[ix] < 10) {
			nvec.push_back(vec[ix]);
		}
	}
	return nvec;
}
bool less_than(int a, int b) { return a < b; }
bool greater_than(int a, int b) { return a > b; }
vector<int> fliter(const vector<int> &vec, int fliter_value, bool (*pred)(int, int))
{
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ix++) {
		if (pred(vec[ix], fliter_value)) {
			nvec.push_back(vec[ix]);
		}
	}
	return nvec;
}

int main(int argc, char const *argv[])
{
	/*
	int inta[] = {1, 2, 3, 4, 5, 19, 29, 39, 45, 46, 65, 76, 765, 75, 4};
	vector<int> a(inta, inta + 14);
	vector<int> res_less = fliter(a, 20, less_than);
	vector<int> res_great = fliter(a, 20, greater_than);
	printf("less_than:\n");
	for (int i = 0; i < res_less.size(); i++)
		printf("%d\n", res_less[i]);
	printf("greater_than:\n");
	for (int i = 0; i < res_great.size(); i++)
		printf("%d\n", res_great[i]);
		*/
	ifstream in_file("E:\\a.txt");
	ofstream out_file("E:\\b.txt");
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;
	vector<string> text;
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	ostream_iterator<string> os(out_file, "<>");
	copy(text.begin(), text.end(), os);
	return 0;
}
