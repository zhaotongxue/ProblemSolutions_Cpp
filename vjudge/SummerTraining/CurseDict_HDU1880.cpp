#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
const int seed = 131;
unsigned int BKDRHash(string str)
{
	int len = str.length();
	int thash = 0;
	for (int i = 0; i < len; i++) {
		thash = thash * seed + str[i];
	}
	return (thash & 0x7FFFFFFF);
}
int main()
{
	cin.sync_with_stdio(true);
	cout.sync_with_stdio(true);
	// unordered_map<string, string> title;
	// unordered_map<string, string> content;
	unordered_map<int, string> title;
	unordered_map<int, string> content;
	string inputed;
	while (getline(cin, inputed), inputed != "@END@") {
		// while (gets(inputed), inputed != "@END@") {
		int symbolpos = inputed.find("]");
		// title[inputed.substr(1, symbolpos - 1)] = inputed.substr(symbolpos + 2, inputed.size() - symbolpos);
		// content[inputed.substr(symbolpos + 2, inputed.size() - symbolpos)] = inputed.substr(1, symbolpos - 1);
		title[BKDRHash(inputed.substr(1, symbolpos - 1))] = inputed.substr(symbolpos + 2, inputed.size() - symbolpos);
		content[BKDRHash(inputed.substr(symbolpos + 2, inputed.size() - symbolpos))] = inputed.substr(1, symbolpos - 1);
	}
	int cases;
	cin >> cases;
	cin.get();
	while (cases--) {
		getline(cin, inputed);
		// gets(inputed);
		if (!inputed.find('[')) {
			unordered_map<int, string>::iterator at = title.find(BKDRHash(inputed.substr(1, inputed.size() - 2)));
			if (at != title.end()) {
				// cout << title[inputed.substr(1, inputed.size() - 2)] << endl;
				cout << (*at).second << endl;
			} else {
				cout << "what?" << endl;
			}
		} else {
			unordered_map<int, string>::iterator at = content.find(BKDRHash(inputed));
			if (at != content.end()) {
				// cout << '[' << content[inputed] << ']' << endl;
				cout << (*at).second << endl;
			} else {
				cout << "what?" << endl;
			}
		}
	}

	return 0;
}