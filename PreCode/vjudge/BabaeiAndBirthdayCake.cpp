#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const int maxn=100000;
int result=0;
int size=0;
struct cake{
    int r;
    int h;
    int v;
    cake(){};
    cake(int r,int h):r(r),h(h),v(r*r*h){};
    bool operator>(const struct cake& c) const{
        return (this->r>=c.r&&this->h>c.h)||(this->h>=c.h&&this->r>c.r);
    }
};
cake cakes[maxn];
int dp[maxn];
#define pi 3.14159265358979323846233
void get_max(int index){
    int max_index=-1;
    bool can_be_max=1;
    for(int i=index-1;i>=0;i--){
        if(cakes[i]>cakes[index]){
            can_be_max=0;
            break;
        }
        if(cakes[index]>cakes[i]&&(max_index==-1||dp[i]>dp[max_index])){
                max_index=i;
        }
    }
    if(!can_be_max){
        cakes[index]=-1;
    }
    if(max_index==-1){
        dp[index]=cakes[index].v;
    }else{
        dp[index]=dp[max_index]+cakes[index].v;
    }
    if(dp[index]>result) result=dp[index];
}
int main(){
    int r,h;
    int cases;
    cin>>cases;
    while(cases--){
        cin>>r>>h;
        cake k(r,h);
        cakes[size++]=k;
    }
    dp[0]=cakes[0].v;
    result=dp[0];
    for(int i=1;i<size;i++){
        get_max(i);
    }
    //printf("%.9f\n",pi*result);
    cout<<setiosflags(ios::fixed)<<setprecision(9)<<pi*result<<endl;
    return 0;
}
