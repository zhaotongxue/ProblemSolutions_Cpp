#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
#define maxn 100005
int main(){
    cout.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int pen[n];
    for(int i=0;i<n;i++){
        cin>>pen[i];
    }
    set<int> s;
    while(m--){
        char c;
        int arg1,arg2;
        cin>>c>>arg1>>arg2;
        if(c=='Q'){
            for(int i=arg1-1;i<arg2;i++){
                s.insert(pen[i]);
            }
            cout<<s.size()<<endl;
            s.clear();
        }else{
            pen[arg1-1]=arg2;
        }
    }
    return 0
}