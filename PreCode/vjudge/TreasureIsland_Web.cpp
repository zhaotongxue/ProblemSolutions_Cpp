#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX=2550;
#define MS(a,b) memset(a,b,sizeof(a))
char input[MAX];
bool marked[MAX];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int s0=0;
int s=0;
queue<int> q;
void bfs(int y,int x,int sy,int sx){
    s++;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=n%sx+dx[i];
            int ty=n/sx+dy[i];
            if(tx<sx&&ty<sy&&tx>=0&&ty>=0&&!marked[ty*sx+tx]){
                if(input[ty*sx+tx]=='.'||input[ty*sx+tx]=='?'||input[ty*sx+tx]=='*'){
                    // printf("y:%d x:%d\n",ty,tx);
                    q.push(ty*sx+tx);
                    marked[ty*sx+tx]=1;
                    s++;
                    if(input[ty*sx+tx]=='?') input[ty*sx+tx]='*';
                }
            }
        }
    }
}
int main(){
    MS(marked,0);
    int y,x;
    scanf("%d%d",&y,&x);
    int init_x,init_y;
    for(int i=0;i<y;i++){
        for(int m=0;m<x;m++){
            cin>>input[i*x+m];
        }
    }
    int pieces=0;
    for(int i=0;i<y;i++){
        for(int m=0;m<x;m++){
            if(input[i*x+m]=='.'&&!marked[i*x+m]){
                marked[i*x+m]=1;
                q.push(i*x+m);
                bfs(i,m,y,x);
                pieces++;
                init_x=m;
                init_y=i;
            }
        }
    }
    if(pieces!=1){
        printf("Impossible");
    }else{
        s0=s;
        // printf("new line\n");
        for(int i=0;i<y;i++){
            for(int m=0;m<x;m++){
                if(input[i*x+m]=='*'){
                    s=0;
                    MS(marked,0);
                    input[i*x+m]='#';
                    q.push(init_y*x+init_x);
                    //marked[i*x+m]=1;
                    marked[init_y*x+init_x]=1;
                    bfs(i,m,y,x);
                    if(s==s0-1){
                        printf("Ambiguous");
                        return 0;
                    }
                    input[i*x+m]='*';
                }
            }
        }

        for(int i=0;i<y;i++){
            for(int m=0;m<x;m++){
                if(input[i*x+m]=='.'||input[i*x+m]=='*') printf(".");
                else printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}
