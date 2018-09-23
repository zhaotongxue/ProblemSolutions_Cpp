// SpreadsheetTracking_512
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 55;
int main()
{
	int y, x;
	int arr[maxn][maxn];
	while (scanf("%d%d", &y, &x) && y != 0) {
		memset(arr, 0, sizeof(int) * maxn * maxn);
		int cmdcnt = 0;
		scanf("%d", &cmdcnt);
		while (cmdcnt--) {
			char cmd[2];
			int subcmdcnt = 0;
			scanf("%s", cmd);
			if (cmd == "DC") {
				scanf("%d", &subcmdcnt);
				while (subcmdcnt--) {
					int n;
					scanf("%d", &n);
					for (int i = 1; i <= y; i++) {
						for (int j = n; j <= x; j++) {
							arr[i][n] = arr[i][n + 1];
						}
					}
				}
			} else if (cmd == "DR") {
				scanf("%d", &subcmdcnt);
				while (subcmdcnt--) {
				}

			} else if (cmd == "IC") {
				scanf("%d", &subcmdcnt);
				while (subcmdcnt--) {
				}

			} else if (cmd == "IR") {
				scanf("%d", &subcmdcnt);
				while (subcmdcnt--) {
				}
			} else if (cmd == "EX") {
			}
		}
	}
	return 0;
}
