#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <set>
#include <cstdio>
using namespace std;
#define maxn 1005
int q[maxn];
vector<int> v;
void div(int m){
   for (int i = 2; i * i <= m; i++)
   {
       if (m % i == 0)
       {
           v.push_back(i);
           while (m % i == 0)
               m /= i;
       }
    }
    if(m>1) v.push_back(m);
}
int compose(int n){
    memset(q,0,maxn);
    int size=0,sum=0;
    q[size++]=-1;
    for(unsigned int i=0;i<v.size();i++){
        int pre_size=size;
        for(int j=0;j<pre_size;j++){
            q[size++]=q[j]*v[i]*(-1);
        }
    }
    for (int i = 1; i < size;i++){
        sum += n / q[i];
    }
        return sum;
}
int get_k(int &k,int s,int e){
    if(s==e) return s;
    int mid=s+(e-s)/2;
    int calc_num=mid-s+1-compose(mid);
    printf("%d before:%d\n", mid, calc_num);
    // if(calc_num==k) return mid;
    if(calc_num>=k) return get_k(k,s,mid-1);
    else if(calc_num<k) return get_k(k,mid+1,e);
}
int main(){
    printf("Start Output:\n");
    int m,k;
    while(cin>>m){
        cin>>k;
        div(m);
        printf("%d\n",get_k(k,0,m-1));
    }
    return 0;
}