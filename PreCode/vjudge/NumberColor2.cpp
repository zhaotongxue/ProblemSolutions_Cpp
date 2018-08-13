#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
#define maxn 100005
int block_size=0;
struct BlockBit
{
    int left;
    int right;
    int color;
    BlockBit(){};
    BlockBit(int left,int right,int color):left(left),right(right),color(color){};
};
BlockBit bb[maxn];
int main(){
    cout.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int pen[n];
    for(int i=0;i<n;i++){
        cin>>pen[i];
        if(block_size>0&&bb[block_size-1].color==pen[i]){
            bb[block_size-1].right+=1;
        }else{
            block_size++;
            BlockBit b(i,i,pen[i]);
            bb[i]=b;
        }
    }
    set<int> s;
    while(m--){
        char c;
        int arg1,arg2;
        cin>>c>>arg1>>arg2;
        if(c=='Q'){
            for(int i=arg1-1;i<arg2;i=bb[i].right+1){
                s.insert(bb[i].color);
            }
            cout<<s.size()<<endl;
            s.clear();
        }else{
            pen[arg1-1]=arg2;
            if(bb[arg-1].left<arg-1&&bb[arg-1].right>arg-1){

            }
        }
    }
    return 0;
}