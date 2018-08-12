#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <iomanip>
using namespace std;
#define DEBUG
int main()
{
    int all, id1, id2;
    scanf("%d%d%d", &all, &id1, &id2);
    int cases = 0;
    while (id1 != id2)
    {
        all /= 2;
        id1 = (id1 + 1) / 2;
        id2 = (id2 + 1) / 2;
        cases++;
    }
    if (all == 1)
    {
        printf("Final!");
    }
    else
    {
        printf("%d", cases);
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}