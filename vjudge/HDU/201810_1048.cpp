#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		int total, min_val;
		scanf("%d", &total);
		min_val = total;
		for (int i = 0; i * 150 <= total; i++) {
			for (int j = 0; j * 200 <= total - i * 150; j++) {
				for (int k = 0; k * 350 <= total - i * 150 - j * 200; k++) {
					if (total - i * 150 - j * 200 - k * 350 >= 0 && total - i * 150 - j * 200 - k * 350 < min_val) {
						min_val = total - i * 150 - j * 200 - k * 350;
					}
				}
			}
		}
		printf("%d\n", min_val);
	}
	return 0;
}
