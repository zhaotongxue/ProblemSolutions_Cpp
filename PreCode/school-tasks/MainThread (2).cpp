#include <iostream>
using namespace std;
int res = 0, num = 0;
bool CheckRes(int arrays[]) {
	for (int i = 0; i < 9; i++) {
		if (arrays[i] != arrays[i + 1]) {
			return false;
		}
	}
	res = arrays[0];
	return true;
}
void HandleCandy(int arrays[]) {
	while (!CheckRes(arrays)) {
		num++;
		int temp = arrays[9];
		arrays[9] =arrays[9]/2;
		for (int i = 9; i>=1;i--) {
			arrays[i] += arrays[i-1] / 2;
			arrays[i-1] =arrays[i-1]/ 2;
		}
		//arrays[0] = arrays[0] / 2;
		arrays[0] += temp / 2;
		//cout << arrays[0] << arrays[1] << arrays[2] << arrays[3]<<endl;
		for (int i = 0; i < 10; i++) {
			if (arrays[i] % 2 != 0) {
				arrays[i]++;
			}
		}
	}
}
int CalcJieCheng(int n) {
	int res=1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
int CalcPaiLie(int n,int m) {
	return CalcJieCheng(n) / CalcJieCheng(n - m);
}
int main() {
	/*
	int arrays[10];
	cin >> arrays[0] >> arrays[1] >> arrays[2] >> arrays[3] >> arrays[4] >> arrays[5] >> arrays[6] >> arrays[7] >> arrays[8] >> arrays[9];
	HandleCandy(arrays);
	cout << num << " " << res;
	*/
	/*
	int arrays[] = { 1,1 };
	int n;
	cin >> n;
	if (n <= 2) {
		cout << 1;
		return 0;
	}
	for(int i=0;i<n-2;i++){
		int temp = arrays[1];
		arrays[1] += arrays[0];
		arrays[0] = temp;
	}
	cout << arrays[1];
	*/
	int n,m;
	cin >> n >> m;
	int s=CalcPaiLie(n, m);
	cout << s;
	system("pause");

	return 0;
}
