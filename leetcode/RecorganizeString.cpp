#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

// int abs(int &a, int &b) { return a >= b ? a - b : b - a; }
string reorganizeString(string S)
{
	string res_null("");
	if (S.size() == 0) return res_null;

	char res[505];
	memset(res, '\0', sizeof(char) * 505);
	int count[255];
	int max = 0, max_index = 0;
	memset(count, 0, sizeof(int) * 255);
	// count all,index==char
	for (int i = 0; i < S.size(); i++) {
		++count[S.at(i)];
		if (count[S.at(i)] > max) {
			max_index = S.at(i);
			max = count[S.at(i)];
		}
	}
	// if max is more than half of size,return false;
	if (max > (S.size() + 1) / 2) return res_null;
	int pos = 0;

	for (int i = 0; i < count[max_index]; i++, pos += 2) {
		if (pos >= S.size()) pos = 1;
		res[pos] = (char)max_index;
	}
	count[max_index] = 0;

	for (int i = 0; i < 255; i++) {
		for (int k = 0; k < count[i]; k++, pos += 2) {
			if (pos >= S.size()) pos = 1;
			res[pos] = (char)i;
		}
	}

	res[S.size()] = '\0';
	return string(res, S.size() + 1);
}
int main()
{
	string s = "aab";
	cout << reorganizeString(s) << endl;
	return 0;
}