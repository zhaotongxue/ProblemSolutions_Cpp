#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long int
set<ll> pets;
set<ll> p;
static ll mod=1000000;
ll dishappy=0;
void get_pets(){
    if(pets.empty()||p.empty()) return;
    if(pets.size()>p.size()){
        set<int>::iterator temp=p.begin();
        ll pa=*temp;
        p.erase(temp);
        set<ll>::iterator it=pets.lower_bound(pa);
        set<ll>::iterator it2;
        if(it==pets.end()) it--;
        if(it!=pets.begin()){
            it2=it;
            it2--;
            if(abs(pa-*it2)<=abs(pa-*it)){
                it--;
            }
        }
        dishappy+=abs(pa-*it)%mod;
        dishappy%=mod;
        pets.erase(it);
            /*
        }
        {
            it--;
            dishappy+=abs(pa-*it);
            pets.erase(it);
        }else if(it==pets.begin()){
            dishappy+=abs(pa-*it);
            pets.erase(it);
        }else{
            int v_right=abs(pa-*it);
            it--;
            int v_left=abs(pa-*it);
            if(v_right<v_left){
                it++;
                dishappy+=v_right;
                pets.erase(it);
            }else{
                dishappy+=v_left;
                pets.erase(it);
            }
            */
        }
    // }
    //动物选人
    else{
        set<ll>::iterator temp=pets.begin();
        ll pa=*temp;
        pets.erase(temp);
        set<ll>::iterator it=p.lower_bound(pa);
        set<ll>::iterator it2=it;
        if(it==p.end()){
            it--;
        }
        if(it!=p.begin()){
            it2--;
            if(abs(pa-*it2)<=abs(pa-*it)) it--;
        }
        dishappy+=abs(pa-*it)%mod;
        dishappy%=mod;
        p.erase(it);
            /*
            dishappy+=abs(pa-*it);
            p.erase(it);
        }else if(it==p.begin()){
            dishappy+=abs(pa-*it);
            p.erase(it);
        }else{
            int v_right=abs(pa-*it);
            it--;
            int v_left=abs(pa-*it);
            if(v_right<v_left){
                it++;
                dishappy+=v_right;
                p.erase(it);
            }else{
                dishappy+=v_left;
                p.erase(it);
            }
        }
        */
    }
}
int main(){
    int cases;
    // cout.sync_with_stdio(false);
    cin>>cases;
    while(cases--){
        ll identifity;
        ll a;
        cin>>identifity>>a;
        if(!identifity){
            pets.insert(a);
        }else{
            p.insert(a);
        }
        get_pets();
    }
    cout<<dishappy;
    return 0;
}
