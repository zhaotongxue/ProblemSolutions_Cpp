#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <iomanip>
using namespace std;
#define DEBUG
int charAt(std::string s, int index)
{
    if (index < s.length())
        return s.at(index);
    else
        return -1;
}
void exch(std::string s[], int x, int y)
{
    std::string st = s[x];
    s[x] = s[y];
    s[y] = st;
}
void sort(std::string s[], int lo, int hi, int d)
{
    if (hi <= lo)
        return;
    int lt = lo, gt = hi;
    int v = charAt(s[lo], d);
    int i = lo + 1;
    while (i <= gt)
    {
        int t = charAt(s[i], d);
        if (t < v)
            exch(s, lt++, i++);
        else if (t > v)
            exch(s, i, gt--);
        else
            i++;
    }
    sort(s, lo, lt - 1, d);
    if (v >= 0)
        sort(s, lt, gt, d + 1);
    sort(s, gt + 1, hi, d);
}
void sort(std::string s[])
{
    sort(s, 0, s->size(), 0);
}
int main()
{
    std::string s[] = {"dfghjk", "abklsdgjalkbgjka", "ajsdobvr", "skjhjfhivt", "pohbjtkh", "jilnclisksj"};
    printf("size is:%d\n", s->size());
    sort(s);
    for (int i = 0; i < s->size(); i++)
    {
        printf("%s\n", s[i].c_str());
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}