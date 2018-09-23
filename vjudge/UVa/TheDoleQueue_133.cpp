#include <cstdio>
#include <cstring>
#include <iostream>
bool isnotend(int* arr, int len)
{
	for (int i = 1; i <= len; i++) {
		if (arr[i] > 0) return 1;
	}
	return 0;
}
int main()
{
	int n, k, m;
	int arr[25];
	while (scanf("%d%d%d", &n, &k, &m) && n > 0) {
		memset(arr, -1, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			arr[i] = i;
		}
		int A = 0, B = n + 1;
		while (isnotend(arr, n)) {
			for (int i = 1; i <= k; i++) {
				do {
					A = A + 1;
					if (A > n) A = 1;
				} while (arr[A] < 0);
			}
			for (int i = 1; i <= m; i++) {
				do {
					// B = B - 1 > 0 ? B - 1 : n;
					B = B - 1;
					if (B < 0) B = n;
				} while (arr[B] < 0);
			}
			if (A == B)
				printf("%3d", A);
			else
				printf("%3d%3d", A, B);

			arr[A] = -1;
			arr[B] = -1;
			if (isnotend(arr, n)) printf(",");
		}
		printf("\n");
	}
	return 0;
}