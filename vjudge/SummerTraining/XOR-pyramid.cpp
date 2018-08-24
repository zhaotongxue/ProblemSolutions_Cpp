#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=5010;
#define FOR(i,x,n) for(int i=x;i<n;i++)
int dp[maxn][maxn];
typedef long long ll;
void init(ll arr[],int size){
    FOR(i,1,size){
        FOR(k,0,size-i+1){
            dp[k][k+i]=dp[k+1][k+i]^dp[k][k+i-1];
        }
    }
    FOR(i,1,size){
        FOR(k,0,size-i+1){
            dp[k][k+i]=max(dp[k][k+i],max(dp[k+1][k+i],dp[k][k+i-1]));
        }
    }
}
int main(int argc, char const *argv[])
{
    memset(dp,-1,maxn*maxn);
    int array_size;
    scanf("%d",&array_size);
    ll arr[array_size];
    FOR(i,0,array_size) scanf("%lld",&arr[i]),dp[i][i]=arr[i];
    init(arr,array_size);
    int queries;
    scanf("%d",&queries);
    while(queries--){
        int l,r;
        scanf("%d%d",&l,&r);
        // if(dp[l-1][r-1]==-1) getVal(arr,l-1,r-1);
        printf("%d\n",dp[l-1][r-1]);
    }
    return 0;
}
