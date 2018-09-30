#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
char fir[105], sec[105];
char codes[26];
int ifir[26], isec[26];
void init()
{
	codes[0] = 'Z';
	for (int i = 1; i < 26; i++) {
		codes[i] = 'A' + i - 1;
	}
}
int main()
{
	// while (scanf("%s%s", fir, sec) != EOF) {
	init();
	while (cin >> fir >> sec) {
		memset(ifir, 0, sizeof(ifir));
		memset(isec, 0, sizeof(isec));
		for (int i = 0; i < strlen(fir); i++) {
			ifir[codes[fir[i] - 'A'] - 'A']++;
		}
		for (int i = 0; i < strlen(sec); i++) {
			isec[sec[i] - 'A']++;
		}
		sort(ifir, ifir + 26);
		sort(isec, isec + 26);
		bool thesame = 1;
		for (int i = 0; i < 26; i++) {
			if (ifir[i] != isec[i]) {
				thesame = 0;
				break;
			}
		}
		if (thesame)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}