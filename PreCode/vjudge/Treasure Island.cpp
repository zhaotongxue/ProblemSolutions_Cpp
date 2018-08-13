#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
/*
5 7
#######
#.###.#
#.?.?.#
#.###.#
#######
6 7
#######
#.....#
#.###.#
#.#?#.#
#.###.#
#######
*/
char res[1000000];
int init_y=-1,init_x=-1;
int total=0;
int all_nums=0;
void init(char arr[],int y,int x){
    for(int i_y=0;i_y<y;i_y++)
        for(int i_x=0;i_x<x;i_x++)
            if(arr[i_y*x+i_x]=='.'){
                    init_y=i_y;
                    init_x=i_x;
                    return;
            }
}
bool check(char arr[],int n,bool marked[]){
    for(int i=0;i<n;i++){
        if(arr[i]=='.'&&!marked[i]){
            return false;
        }
    }
    return true;
}
bool bfs(char arr[],int y,int x){
    bool marked[y*x];
    queue<int> q;
    memset(marked,0,sizeof(marked));
    q.push(init_y*x+init_x);
    marked[init_y*x+init_x]=1;
    int ty,tx;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        ty=n/x;
        tx=n%x;
        if(ty-1>=0&&arr[(ty-1)*x+tx]=='.'&&!marked[(ty-1)*x+tx]){
            q.push((ty-1)*x+tx);
            marked[(ty-1)*x+tx]=1;
        }
        if(tx-1>=0&&arr[ty*x+tx-1]=='.'&&!marked[ty*x+tx-1]){
            q.push(ty*x+tx-1);
            marked[ty*x+tx-1]=1;
        }
        if(ty+1<y&&arr[(ty+1)*x+tx]=='.'&&!marked[(ty+1)*x+tx]){
            q.push((ty+1)*x+tx);
            marked[(ty+1)*x+tx]=1;
        }
        if(tx+1<x&&arr[ty*x+tx+1]=='.'&&!marked[ty*x+tx+1]){
            q.push(ty*x+tx+1);
            marked[ty*x+tx+1]=1;
        }
    }
    return check(arr,y*x,marked);
}
void enumAll(char arr[],int pos,int y,int x){
    for(int i=pos;i<y*x;i++){
        if(arr[i]=='?'){
            arr[i]='.';
            enumAll(arr,i+1,y,x);
            arr[i]='#';
            enumAll(arr,i+1,y,x);
            // arr[i]='?';
            return;
        }
    }
    if(bfs(arr,y,x)){
        all_nums++;
        memcpy(res,arr,y*x);
    }
}
/*
void print_it(char arr[],int pos,int y,int x){
    for(int i=pos;i<y*x;i++){
        if(arr[i]=='?'){
            arr[i]='.';
            enumAll(arr,i+1,y,x);
            arr[i]='#';
            enumAll(arr,i+1,y,x);
            return;
        }
    }
    if(bfs(arr,y,x)){
        for(int i_y=0;i_y<y;i_y++){
            for(int i_x=0;i_x<x;i_x++){
                printf("%c",arr[i_y*x+i_x]);
            }
            printf("\n");
        }
    }
}
*/
int main(){
    int y,x;
    scanf("%d%d",&y,&x);
    char arr[y*x];
    for(int i_y=0;i_y<y;i_y++){
        for(int i_x=0;i_x<x;i_x++){
            cin>>arr[i_y*x+i_x];
        }
    }
    init(arr,y,x);
    enumAll(arr,0,y,x);
    if(all_nums==1){
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                printf("%c",res[i*x+j]);
            }
            printf("\n");
        }
    }else if(all_nums>1){
        printf("Ambiguous");
    }else{
        printf("Impossible");
    }
    return 0;
}
