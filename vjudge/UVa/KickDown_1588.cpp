#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 105;
char masterstr[maxn], drivenstr[maxn];
int master[maxn], driven[maxn];

int main()
{
	while (cin >> masterstr >> drivenstr) {
		memset(master, 0, sizeof(master));
		memset(driven, 0, sizeof(driven));
		for (int i = 0; i < strlen(masterstr); i++) {
			master[i] = masterstr[i] - '0';
		}
		for (int i = 0; i < strlen(drivenstr); i++) {
			driven[i] = drivenstr[i] - '0';
		}
		int res = strlen(drivenstr) + strlen(masterstr);
		int* smax = strlen(drivenstr) > strlen(masterstr) ? driven : master;
		int* smin = strlen(drivenstr) > strlen(masterstr) ? master : driven;
		int maxsize = max(strlen(drivenstr), strlen(masterstr));
		int minsize = min(strlen(drivenstr), strlen(masterstr));
		int* total = new int[maxsize + 2 * minsize];
		for (int i = 0; i < maxsize + minsize; i++) {
			memset(total, 0, sizeof(int) * (maxsize + 2 * minsize));
			for (int k = 0; k < maxsize; k++) {
				total[minsize + 1 + k] = smax[k];
			}
			for (int j = 0; j < minsize; j++) {
				total[j + i] += smin[j];
			}
			int ok = 1;
			for (int j = 0; j < maxsize + 2 * minsize; j++) {
				if (total[j] > 3) ok = 0;
			}
			if (ok) {
				int len = 0;
				for (int j = 0; j < maxsize + 2 * minsize; j++) {
					if (total[j] != 0) len++;
				}
				res = min(res, len);
			}
		}
		/*
		// bool okpos = -1;
		for (int i = 0; i < strlen(masterstr); i++) {
			bool ok = 1;
			for (int j = 0, k = i; j < strlen(drivenstr) && k < strlen(masterstr); j++, k++) {
				// for(int k=i;k<strlen(masterstr);k++){ }
				if (master[i] + driven[j] > 3) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				res = i + strlen(drivenstr);
				if (res < max(strlen(drivenstr), strlen(masterstr))) res = max(strlen(drivenstr), strlen(masterstr));
				break;
			}
		}
		*/
		printf("%d\n", res);
	}
	return 0;
}