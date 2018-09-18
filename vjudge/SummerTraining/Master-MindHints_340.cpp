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
int main() {

    int size = 0;
    cin >> size;
    int* first=new int[size];
    int*  second=new int[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &first[i]);
    }
    while (true) {
        int the_same = 0;
        for (int i = 0; i < size; i++) {
            scanf("%d", &second[i]);
            if (second[i] == first[i])
                the_same++;
        }
        if (second[0] == 0)
            break;
        int all_same=0;
        int c1=0, c2=0;
        for (int i = 1; i < 10; i++) {
            for (int ij = 0; ij < size; ij++) {
                if (first[ij] == i)
                    c1++;
                if (second[ij] == i)
                    c2++;
            }
            all_same += min(c1, c2);
        }
        printf("%d %d\n", the_same, all_same - the_same);
        first=second;
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}
