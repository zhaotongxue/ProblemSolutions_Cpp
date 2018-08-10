#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
#define maxn 100005
ll get(ll pos){
    ll count=0;
    set<ll> s;
    ll q[maxn];//存A B C -AB -AC -BC ABC
    for(ll i=2;i<=sqrt(pos);i++){
        if(pos%i==0) s.insert(i);//最小的质数相乘的形式
        while(pos%i==0) pos/=i;
    }
    if(pos!=1) s.insert(pos);

    unsigned int size=0;
    q[size++]=-1;
    for(set<ll>::iterator it=s.begin();it!=s.end();it++){
        unsigned int pre_size=size;
        for(unsigned int j=0;j<pre_size;j++){
            q[size++]=-q[j]*(*it);
        }
    }
    for(unsigned int i=1;i<size;i++){
        count+=pos/q[i];
    }
    return count;
}
int main(){
    ll cases;
    scanf("%lld",&cases);
    for(ll times=1;times<=cases;times++){
        ll count=0;
        ll start,end,target;
        scanf("%lld%lld%lld",&start,&end,&target);
        /*
        重复算了很多，比如A，B，C，AB，ABC，BC，AC这种，最后还要减去的
        就是 A+B+C-AB-BC-AC+ABC相隔变号

        看了别人的方法，都从一点开始算，最后减去就好了，想的少一点，计算量也没打多少
        set<int> divisors;
        for(ll i=2;i<int(sqrt(target))+1;i++){
            if(target%i==0){
                 divisors.insert(i);
                 divisors.insert(target/i);
            }
        }
        divisors.insert(target);
        count+=(end-target)/target*(target-divisors.size());
        int pre_size=distance(divisors.begin(),divisors.lower_bound(start))-1;
        if(pre_size<0) pre_size=0;
        ll count1=target-start+1-divisors.size()+pre_size;
        pre_size=distance(divisors.begin(),divisors.lower_bound(end%target))-1;
        if(pre_size<0) pre_size=0;
        ll count2=end%target-pre_size;
        count+=count1+count2;
        */
        printf("Case #%d: %lld\n",times,get(end)-get(start-1));
    }
    return 0;
}
