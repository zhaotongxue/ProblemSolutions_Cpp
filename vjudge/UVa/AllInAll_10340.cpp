#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
// char str1[1000000], str2[1000000];
string str1, str2;
int main()
{
	// while (scanf("%s", str1) != EOF) {
	// scanf("%s", str2);
	while (cin >> str1 >> str2) {
		int idx = 0;
		int yes = 1;
		for (int i = 0; i < str1.length() && yes; i++) {
			while (idx < str2.length() && str2[idx++] != str1[i]) {
				if (idx == str2.length()) yes = 0;
			}
		}
		if (yes)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}