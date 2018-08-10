#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n=5;
    int matrix[5][5];
    memset(matrix,0,sizeof(matrix));
    matrix[0][0]=1;
    int num=1;
    int x=0,y=0;
    while(num<n*n){
        while(x<n-1&&matrix[y][x+1]==0) matrix[y][++x]=++num;
        while(y<n-1&&matrix[y+1][x]==0) matrix[++y][x]=++num;
        while(x>0&&matrix[y][x-1]==0) matrix[y][--x]=++num;
        while(y>0&&matrix[y-1][x]==0) matrix[--y][x]=++num;
    }
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cout<<matrix[y][x]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}