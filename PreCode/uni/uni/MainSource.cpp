#include <iostream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define maxn 100005
int q[maxn];
vector<int> v;
void div(int m) {
	v.clear();
	for (int i = 2; i*i <= m; i++) {
		if (m%i == 0) {
			v.push_back(i);
			while (m%i == 0) m /= i;
		}
	}
	if (m>1) v.push_back(m);
}
int compose(int n) {
	memset(q, 0, maxn);
	int size = 0, sum = 0;
	q[size++] = -1;
	for (unsigned int i = 0; i<v.size(); i++) {
		int pre_size = size;
		for (int j = 0; j<pre_size; j++) {
			q[size] = q[j] * v[i] * (-1);
			sum += n / q[size++];
		}
	}
	return sum;
}
int get_k(int &k, int s, int e) {
	int mid = s + (e - s) / 2;
	int calc_num = e-s+1-compose(mid);
	if (calc_num == k) return mid;
	else if (calc_num>k) return get_k(k, s, mid - 1);
	else if (calc_num<k) return get_k(k, mid + 1, e);

	return -1;
}
int main() {
	int m, k;
	while (cin >> m) {
		cin >> k;
		div(m);
		printf("%d\n", get_k(k, 0, m-1));
	}
	return 0;
}