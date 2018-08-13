#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<char*> v;
    bool marked[n];
    int tn=n;
    memset(marked,0,sizeof(marked));
    while(n--){
        char* t=new char(101);
        cin>>t;
        v.push_back(t);
    }
    vector<int> vi;
    vector<int> v2;
    while(m--){
        int t;
        cin>>t;
        vi.push_back(t-1);
        marked[t-1]=1;
    }
    //check length
    int length=strlen(v[vi[0]]);
    for(int i=1;i<vi.size();i++){
       if(strlen(v[vi[i]])!=length){
            printf("No");
            return 0;
       }
    }
    for(int i=0;i<tn;i++){
        // printf("\n%d",strlen(v[i]));
        if(strlen(v[i])==length&&!marked[i]){
            v2.push_back(i);
            // printf("V2:%d\n",i);
        }
    }
    vector<char> res;
    for(int t=0;t<strlen(v[vi[0]]);t++){
        char c=v[vi[0]][t];
        bool same=1;
        for(int i=1;i<vi.size();i++){
            if(v[vi[i]][t]!=c){
                res.push_back('?');
                same=0;
                break;
            }
        }
        if(same) res.push_back(c);
    }
    for(int i=0;i<v2.size();i++){
        bool can=1;
        for(int k=0;k<length;k++){
            if(res[k]=='?') continue;
            if(res[k]!=v[v2[i]][k]){
                can=0;
            }
        }
        if(can){
            printf("No");
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=0;i<res.size();i++){
        printf("%c",res[i]);
    }
    return 0;
}