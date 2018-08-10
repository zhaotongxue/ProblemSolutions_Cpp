#include <cstring>
#include <iostream>
#include <sstream>
// using namespace std;
#define DEBUG
const int MAX_N = 100005;
int in_count = 0, out_count = 0;
int cases = 0;
const int SIGMA_SIZE = 26;
char s[MAX_N + 1];
int sa[MAX_N], buff[2][MAX_N + 1], *rank = buff[0], *t = buff[1], b[MAX_N], h[MAX_N];
int left, right, old_left, old_right;
void init()
{
    memset(s, 0, MAX_N + 1);
    memset(sa, 0, MAX_N);
    memset(buff[0], 0, MAX_N);
    memset(buff[1], 0, MAX_N);
    memset(h, 0, MAX_N);
    memset(b, 0, MAX_N);
    in_count = 0;
    out_count = 0;
    left = right = old_left = old_right = 0;
}
void build_SA(char s[], int n)
{
    int *&pre = t, *&r = t;
    rank[n] = r[n] = -1;
    memset(b, 0, sizeof(int) * SIGMA_SIZE);
    for (int i = 0; i < n; ++i)
        ++b[s[i] - 'a'];
    for (int i = 1; i < SIGMA_SIZE; ++i)
        b[i] += b[i - 1];
    for (int i = n - 1; i >= 0; --i)
        sa[--b[s[i] - 'a']] = i;
    int m = rank[sa[0]] = 0;
    for (int i = 1; i < n; ++i)
        rank[sa[i]] = m += (s[sa[i]] != s[sa[i - 1]]);
    ++m;

    for (int k = 1; m < n; ++m, k *= 2)
    {

        for (int i = 0, p = k; i < n; ++i)
            if (sa[i] >= k)
                pre[p++] = sa[i] - k;
        for (int i = 0; i < k; ++i)
            pre[i] = n - k + i;

        memset(b, 0, sizeof(int) * m);
        for (int i = 0; i < n; ++i)
            ++b[rank[i]];
        for (int i = 1; i < m; ++i)
            b[i] += b[i - 1];
        for (int i = n - 1; i >= 0; --i)
            sa[--b[rank[pre[i]]]] = pre[i];

        m = r[sa[0]] = 0;

        for (int i = 1; i < n; ++i)
            r[sa[i]] = m += (rank[sa[i]] != rank[sa[i - 1]] || rank[sa[i] + k] != rank[sa[i - 1] + k]);
        std::swap(rank, r);
    }
}

void get_height(char s[], int n)
{
    for (int i = 0, h0 = 0; i < n; h0 = std::max(0, h[rank[i]] - 1), ++i)
    {
        if (!rank[i])
            continue;
        int j = sa[rank[i] - 1], &k = h[rank[i]] = h0;
        while (s[i + k] == s[j + k])
            ++k;
    }
}
int main(int argc, char const *argv[])
{
    init();
    while (std::cin.getline(s, MAX_N))
    {
        build_SA(s, strlen(s));
        int cases=0;
        scanf("%d", &cases);
        scanf("%d%d", &left, &right);
        if (cases--)
        {
            in_count += right - left + 1;
            out_count += 3 + right - left; //0 abcdedf\n
        }
        while (cases--)
        {
            old_left = left;
            old_right = right;
            int old_range = old_right - old_left;
            scanf("%d%d", &left, &right);
            int new_range = right - left;
            in_count += right - left + 1;
            if (old_left == left)
            {
                // out_count += 3+abs((right-left)-(old_right-old_left));
                if (new_range > old_range)
                {
                    out_count += 2 + new_range - old_range;
                    if (old_range == 0)
                        out_count += 1;
                    else
                    {
                        while (old_range)
                        {
                            out_count++;
                            old_range /= 10;
                        }
                    }
                }
                else if (new_range <= old_range)
                {
                    out_count += 3;
                }
#ifdef DEBUG
                char s1[std::min(old_right - old_left, right - left)];
                memcpy(s1, s + left, std::min(old_range,new_range));
                printf("Left is same:%d %s\n", 0, s1);
#endif
            }
            else
            {
                int min_index = std::min(rank[old_left], rank[left]) + 1;
                for (int i = std::min(rank[old_left], rank[left]) + 2; i <= std::max(rank[old_left], rank[left]); i++)
                {
                    if (h[rank[i]] < h[rank[min_index]])
                        min_index = i;
                }
                int range = std::min(h[rank[min_index]], std::min(old_right - old_left, right - left));
#ifdef DEBUG
                char s1[range];
                memcpy(s1, s + old_left, range);
                printf("%d %d\n", range, s1);
#endif
                out_count += 2;
                out_count += (right - left) - range;
                if (range == 0)
                    out_count += 1;
                else
                {

                    while (range)
                    {
                        range /= 10;
                        out_count++;
                    }
                }
            }
        }
        printf("%d %d\n", in_count, out_count);
        init();
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}
