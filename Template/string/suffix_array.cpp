//suffix array
#include <algorithm>
#include <cstring>

// using namespace std;
const int MAX_N = 100005;
const int SIGMA_SIZE = 100005;
int b[MAX_N], sa[MAX_N], buff[2][MAX_N + 1], *t = buff[0], *rank = buff[1],h[MAX_N];
void build_SA(char s[], int n)
{
    memset(b, 0, sizeof(int) * SIGMA_SIZE);
    for (int i = 0; i < n; i++)
    {
        ++b[s[i] - 'a'];
    }
    for (int i = 1; i < SIGMA_SIZE; i++)
    {
        b[i] += b[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sa[--b[s[i] - 'a']] = i;
    }

    int m = rank[sa[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        rank[sa[i]] = m += s[sa[i]] != s[sa[i - 1]];
    }
    ++m;
    int *&pre = t, *&r = t;
    rank[n] = r[n] = -1;
    for (int k = 1; m < n; k *= 2, ++m)
    {
        for (int i = 0, p = k; i < n; i++)
        {
            if (sa[i] >= k)
                pre[p++] = sa[i] - k;
        }
        for (int i = 0; i < k; i++)
            pre[i] = n - k + i;
        memset(b, 0, sizeof(int) * m);
        for (int i = 0; i < n; i++)
        {
            ++b[rank[i]];
        }
        for (int i = 1; i < m; i++)
        {
            b[i] += b[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            sa[--b[rank[pre[i]]]] = pre[i];
        }
        m = r[sa[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            r[sa[i]] = m += rank[sa[i]] != rank[sa[i - 1]] || rank[sa[i] + k] != rank[sa[i - 1] + k];
        }
        std::swap(r, rank);
    }
}
void get_height(char s[],int n){
    for (int i = 0, h0 = 0; i < n;h0=std::max(0,h[rank[i]]-1),++i){
        if(!rank[i])
            continue;
        int j = sa[rank[i] - 1], &k = h[rank[i]] = h0;
        while(s[i+k]==s[j+k])
            ++k;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
