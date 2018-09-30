#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int b[10005];
int h[6], w[6];
int main()
{
	while (cin >> h[0] >> w[0]) {
		memset(b, 0, sizeof(b));
		b[h[0]]++;
		b[w[0]]++;
		for (int i = 1; i < 6; i++) {
			cin >> h[i] >> w[i];
			b[h[i]]++;
			b[w[i]]++;
		}
		bool possible = 1;
		for (int i = 0; i < 6; i++) {
			if (b[h[i]] < 4 || b[w[i]] < 4) {
				possible = 0;
				break;
			}
			if (h[i] == w[i] && b[h[i]] < 8) {
				possible = 0;
				break;
			}
		}
		if (possible)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
