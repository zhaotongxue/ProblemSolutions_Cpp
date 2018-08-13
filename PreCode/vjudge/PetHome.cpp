#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
#define mod 1000000
/*
5
0 2
0 4
1 3
1 2
1 5
 */
set<ll> pets;
set<ll> p;
ll dishappy=0;

void get_pets(int identifity,ll a){
    if(identifity==1){
        set<ll>::iterator it=pets.lower_bound(a);
        set<ll>::iterator it2;
        if(it==pets.end()) it--;
        if(it!=pets.begin()){
            it2=it;
            it2--;
            if(abs(a-*it2)<=abs(a-*it)){
                it--;
            }
        }
        dishappy+=abs(a-*it)%mod;
        dishappy%=mod;
        pets.erase(it);
        }
    //动物选人
    else{
        set<ll>::iterator it=p.lower_bound(a);
        set<ll>::iterator it2;
        if(it==p.end()){
            it--;
        }
        if(it!=p.begin()){
            it2=it;
            it2--;
            if(abs(a-*it2)<=abs(a-*it)) it--;
        }
        dishappy+=abs(a-*it)%mod;
        dishappy%=mod;
        p.erase(it);
    }
}
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int identifity;
        ll a;
        cin>>identifity>>a;
        if(identifity==0){
            if(p.empty()) pets.insert(a);
            continue;
        }
        if(identifity==1){
            if(pets.empty()) p.insert(a);
            continue;
        }
        get_pets(identifity,a);
    }
    // printf("%lld\n",dishappy);
    cout<<dishappy<<endl;
    return 0;
}
