#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
vector<LL> v;
LL a, b, n;
// #define DEBUG
LL solve(LL x, LL n)//[1, x]区间与n互质的个数
{
    v.clear();
    for(LL i = 2; i*i <= n; i++)   //求n的质因子（素数因子）
    {
        if(n%i==0)
        {
            v.push_back(i);
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n > 1)
        v.push_back(n);
    #ifdef DEBUG
    for(int i=0;i<v.size();i++)
        printf("v[%d]:[%d]\n",i,v[i]);
    #endif
    LL tsum = 0;
    LL tval, cnt;
 
    //用二进制来1,0来表示第几个素因子是否被用到,如n = 30，三个因子是2,3,5，
    //则i=3时二进制是011，表示第2、3个因子被用到
    for(LL i = 1; i < (1<<v.size()); i++)
    {
        tval = 1;
        cnt = 0;
        for(LL j = 0; j < v.size(); j++)
        {
            if(i & (1<<j))       //判断目前第几个因子被用到
            {
                tval*=v[j];
                #ifdef DEBUG
                printf("tval:%d\n",tval);
                #endif
                cnt++;
            }
        }
        if(cnt&1)       //容斥，奇加偶减
            tsum+=x/tval;
        else
            tsum-=x/tval;
    }
 
    return x-tsum;
}
 
int main()
{
    int t;
    int cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        
        LL ans = solve(b,n) - solve(a-1,n);
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
