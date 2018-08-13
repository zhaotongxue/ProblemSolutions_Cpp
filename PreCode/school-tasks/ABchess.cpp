#include <iostream>
#include <string.h>
#define INT_MIN 0x80000000
using namespace std;
int main()
{
    int row,column;
    cin>>row>>column; 
    int a[row][column][3];
    memset(a,-1,sizeof(int)*3*row*column);
    for(int i=0;i<row;i++){
        for(int k=0;k<column;k++){
            cin>>a[i][k][0];
        }
    }
    for(int i=0;i<row;i++){
        for(int k=0;k<column;k++){
            cin>>a[i][k][1];
        }
    }
    int count=0;
    a[0][0][2]=count%2;
    while(count<row*column){
        count++;
        int best_y=-1,best_x=-1,current_val=INT_MIN;
        for(int c=1;c<column;c++){
            if(a[0][c-1][2]!=-1&&a[0][c][2]==-1&&a[0][c][count%2]+a[0][c][1-count%2]>current_val){
               current_val=a[0][c][count%2]+a[0][c][1-count%2];
               best_y=0;
               best_x=c;
            }
            // if(c>2&&a[0][c-2][2]==-1){
            //     break;
            // }
        }
        for(int r=1;r<row;r++){
            if(a[r-1][0][2]!=-1&&a[r][0][2]==-1&&a[r][0][count%2]+a[r][0][1-count%2]>current_val){
                current_val=a[r][0][count%2]+a[r][0][1-count%2];
                best_y=r;
                best_x=0;
            }
            // if(r>2&&a[r-2][0][2]==-1){
            //     break;
            // }
        }
        for(int y=1;y<row;y++){
            for(int x=1;x<column;x++){
                if(a[y-1][x][2]!=-1&&a[y][x-1][2]!=-1&&a[y][x][2]==-1&&a[y][x][count%2]+a[y][x][1-count%2]>current_val){
                    current_val=a[y][x][count%2]+a[y][x][1-count%2];
                    best_y=y;
                    best_x=x;
                }
            }
        }
        a[best_y][best_x][2]=count%2;
    }
    int score[]={0,0};
    for(int y=0;y<row;y++){
        for(int x=0;x<column;x++){
                score[a[y][x][2]]+=a[y][x][a[y][x][2]];
        }
    }
    cout<<"---------"<<endl;
    for(int y=0;y<row;y++){
        for(int x=0;x<column;x++){
            cout<<a[y][x][2]<<"\t";
        }
        cout<<endl;
    }
    cout<<score[0]<<endl;
    cout<<score[1]<<endl;
    cout<<score[0]-score[1]<<endl;
    return 0;
}