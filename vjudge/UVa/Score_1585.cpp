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
// #define DEBUG
#define maxn 85
int main() {
    int cases = 0;
    scanf("%d", &cases);
    char str[maxn];
    while (cases--) {
        int res = 0, os = 0;
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'O') {
                os++;
                res += os;
            } else {
                os = 0;
            }
        }
        printf("%d\n", res);
    }

#ifdef DEBUG
    system("pause");
#endif
    return 0;
}