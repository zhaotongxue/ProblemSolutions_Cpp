#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
// #define DEBUG
#define maxn 105
char str[2 * maxn];
int main() {
    int cases = 0;
    scanf("%d", &cases);
    while (cases--) {
        // memset(s,0,maxn)
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            str[len + i] = str[i];
        }
        int start = 0;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (str[start + j] > str[j + i]) {
                    start = i;
                    break;
                } else if (str[i + j] > str[start + j]) {
                    break;
                }
            }
        }
        for (int i = 0; i < len; i++) {
            printf("%c", str[start + i]);
        }
        printf("\n");
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}