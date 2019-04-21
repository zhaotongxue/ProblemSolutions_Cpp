// Generate Ugly Number
#include <iostream>
#include <string.h>

using namespace std;
int min(int a, int b) { return a > b ? b : a; }
int ugly_number()
{
	int n;
	// scanf("%d\n", &n);
	cin >> n;
	if (n == 0) return 0;
	if (n < 6) {
		int arr[] = {1, 2, 3, 4, 5};
		return arr[n - 1];
	} else {
		int arr[n];
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 4;
		arr[4] = 5;
		for (int i = 5; i < n; i++) {
			arr[i] = min(2 * arr[i - 1], min(3 * arr[i - 2], 5 * arr[i - 3]));
		}
		return arr[n - 1];
	}
}
int main()
{
	cout.sync_with_stdio(1);
	for (int i = 0; i < 5; i++) {
		cout << ugly_number() << endl;
	}
	return 0;
}