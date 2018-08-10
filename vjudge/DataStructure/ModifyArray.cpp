#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 500005
#define max_block 710

int arr[maxn];
int size;
/*
struct BlockBit
{
    int size;
    char v[max_block];
};
*/
void insert_items(int,int);
void delete_items(int,int);
void make_same(int,int,int);
void reverse_items(int,int);
inline int get_sum(int,int);
int get_max_sum();
void insert_items(int pos,int num){
   memmove(arr+pos+num,arr+pos,size-pos);
    for(int i=0;i<num;i++){
        cin>>arr[pos+i];
    }
    size+=num;
    /*
    int cur=0;
    set<BlockBit>::itertor it=bb.begin();
    for(;it!=bb.end();it++){
        if(cur+*it.size>pos) break;
        cur+=*it.size;
    }
    */
}
void delete_items(int pos,int num){
    memmove(arr+pos,arr+pos+num-1,size-pos-num+1);
    size-=num;
    memset(arr+size,0,maxn-size);
}
void make_same(int pos,int n,int c){
    for(int i=0;i<n;i++){
        arr[pos-1+i]=c;
    }
}
void reverse_items(int pos,int n){
    reverse(arr+pos-1,arr+pos-1+n);
}
inline int get_sum(int pos,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[pos-1+i];
    }
    return sum;
}
int get_max_sum(){
    int m=0;
    for(int i=0;i<size;i++){
        for(int j=size-1;j>=i;j--){
            m=max(m,get_sum(i+1,j-i+1));
        }
    }
    return m;
}
int main() {
    int N,M;
    cin>>N>>M;
    size=N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    while(M--){
        char s[20];
        cin>>s;
        if(s[0]=='M'&&s[2]=='X'){
            printf("%d\n",get_max_sum());
            continue;
        }
        int pos,tot;
        cin>>pos>>tot;
        if(s[0]=='I'){
            insert_items(pos,tot);
        }else if(s[0]=='D'){
            delete_items(pos,tot);
        }else if(s[0]=='R'){
            reverse_items(pos,tot);
        }else if(s[0]=='G'){
            printf("%d\n",get_sum(pos,tot));
        }else{
            int c;
            cin>>c;
            make_same(pos,tot,c);
        }
        /*
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        */
    }
    return 0;
}
