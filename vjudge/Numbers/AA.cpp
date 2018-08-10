// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;
#define maxn 100000005
#define ll long long 
double arr[maxn];
int fabonacci(int n){
    //if(arr[n]!=-1) return arr[n];
    // if(n==2) return 1;
    // if(n==1) return 1;
    // arr[n]=fabonacci(n-1)+fabonacci(n-2);
    // return arr[n];
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<=maxn;i++){
        arr[i]=arr[i-1]+arr[i-2];
        if(arr[i]>=10000) arr[i]/=10;
    }
}
int main(){
    memset(arr,-1,sizeof(int)*maxn);
    fabonacci(maxn);
    ll x;
    while(scanf("%lld",&x)){
        // while(arr[x]>=10000) arr[x]/=10;
        printf("%d\n",(int)arr[x]);
    }
    return 0;
}
