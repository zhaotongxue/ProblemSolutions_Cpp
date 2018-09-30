#include <algorithm>
#include <stdio.h>
int main() {
    int n = 0, cases = 0;
    int *fir, *sec;
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++cases);
        fir = new int[n];
        sec = new int[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &fir[i]);
        }
        while (true) {
            int A = 0, B = 0;
            for (int i = 0; i < n; i++) {
                scanf("%d", &sec[i]);
                if (fir[i] == sec[i])
                    A++;
            }
            if (sec[0] == 0)
                break;
            for (int i = 1; i < 10; i++) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++) {
                    if (fir[j] == i)
                        c1++;
                    if (sec[j] == i)
                        c2++;
                }
                B += std::min(c1, c2);
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}