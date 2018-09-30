#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
using namespace std;
//#define DEBUG
const int maxn = 80;
const double C = 12.01, H = 1.008, O = 16.00, N = 14.01;
int main()
{
	int cases = 0;
	scanf("%d", &cases);
	char molar[maxn];
	while (cases--) {
		scanf("%s", molar);
		int length = strlen(molar);
		double res = 0.0;
		double cur = 0.0;
		for (int i = 0; i < length; i++) {
			if (molar[i] == 'C')
				cur = C;
			else if (molar[i] == 'H')
				cur = H;
			else if (molar[i] == 'O')
				cur = O;
			else if (molar[i] == 'N')
				cur = N;
			int num = 0;
			if (i + 1 == length || !(molar[i + 1] >= '0' && molar[i + 1] <= '9')) {
				res += cur;
			} else if (i + 1 < length && molar[i + 1] >= '0' && molar[i + 1] <= '9') {
				while (i + 1 < length && molar[i + 1] >= '0' && molar[i + 1] <= '9') {
					num = num * 10 + (molar[i + 1] - '0');
					i++;
				}
				res += num * cur;
			}
		}
		printf("%.3f\n", res);
	}
#ifdef DEBUG
	system("pause");
#endif
	return 0;
}