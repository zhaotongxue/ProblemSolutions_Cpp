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
#include <string>
#include <sstream>
// #define DEBUG
#define charcount 256
int count[charcount + 2];
int num;
int charAt(std::string s, int index)
{
    if (index < s.length())
        return s.at(index);
    else
        return -1;
}
void sort(std::string s[], int lo, int hi, int depth)
{
    if (lo >= hi)
        return;
    std::string st[hi - lo + 1];
    memset(count, 0, sizeof(count));
    //统计频率
    for (int i = lo; i <= hi; i++)
    {
        count[charAt(s[i], depth) + 2]++;
    }
    //转为index
    for (int i = 0; i < charcount; i++)
    {
        count[i + 1] += count[i];
    }
#ifdef DEBUG
    printf("start print out index\n");
    for (int i = 0; i < charcount; i++)
    {
        printf("%d ", count[i]);
    }
    printf("print out index end;\n");
#endif
    //拷过来
    for (int i = lo; i <= hi; i++)
    {
        st[count[charAt(s[i], depth) + 1]++] = s[i];
    }
    //返回去
    for (int i = lo; i <= hi; i++)
    {
        s[i] = st[i - lo];
        // std::cout << s[i] << std::endl;
    }
    //继续啦
    for (int i = 0; i < charcount; i++)
    {
        sort(s, lo + count[i], lo + count[i + 1] - 1, depth + 1);
    }
}
int main()
{
    std::string strs[100];
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string str;
        std::cin >> str;
        strs[i] = str;
    }
    sort(strs, 0, num - 1, 0);
    for (int i = 0; i < num; i++)
    {
        std::cout << strs[i] << std::endl;
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}