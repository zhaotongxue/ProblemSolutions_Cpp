// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	unordered_map<string, string> st;
	// string s;
	// string t;
	// getline(cin, s);
	// getline(cin, t);
	// st[s] = t;
	// st[t] = s;
	// cout << (*st.find(s)).second << endl;
	// cout << (st.find("abc") == st.end()) << endl;

	// cout << st.find(s) << endl;
	string inputed;
	getline(cin, inputed);
	int symbolpos = inputed.find("]");
	st[inputed.substr(1, symbolpos - 1)] = inputed.substr(symbolpos + 2, inputed.size() - symbolpos);
	st[inputed.substr(symbolpos + 2, inputed.size() - symbolpos)] = inputed.substr(1, symbolpos - 1);
	// for (unordered_map<string, string>::iterator it = st.begin(); it != st.end(); it++) {
	// 	cout << (*it).first << endl;
	// 	cout << (*it).second << endl;
	// }
	unordered_map<string, string>::iterator it = st.find(inputed.substr(1, symbolpos - 1));
	cout << (*it).first << endl;
	// cout << s.find('0') << endl;
	// cout << s.substr(0, s.find('o')) << endl;
	// cout << s.substr(s.find('o') + 1, s.size() - s.find('o')) << endl;
	// cout << s.substr(1, s.size() - 2) << endl;
	return 0;
}
