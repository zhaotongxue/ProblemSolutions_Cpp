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
#define DEBUG
#define maxn 100005
int ans[maxn];
int main() {
    memset(ans, 0, maxn);
    for (int i = 1; i < maxn; i++) {
        int digit_sum = 0, num = i;
        while (num > 0) {
            digit_sum += num % 10;
            num /= 10;
        }
        if (ans[digit_sum + i] == 0 || i < ans[digit_sum + i]) {
            ans[digit_sum + i] = i;
        }
    }
    int cases, n;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}