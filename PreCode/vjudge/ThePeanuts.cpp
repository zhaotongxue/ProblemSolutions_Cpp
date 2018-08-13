#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Point{
public:
    int y;
    int x;
    int peanuts;
    Point(int y,int x,int peanuts);
};
Point::Point(int y,int x,int peanuts){
    this->y=y;
    this->x=x;
    this->peanuts=peanuts;
}
bool cmp(Point &p1,Point &p2){
    return p1.peanuts>p2.peanuts;
}
/*
int[] searchForMax(int arr[],int m,int n){
    int x,y,max=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(max==0||max<arr[i][j]){
                max=arr[i][j];
                y=i;
                x=j;
            }
        }
    }
    int res[]={y+1,x+1,max};
    return res;
}
*/
int main(int argc, char const *argv[])
{
    int total_num=0;
    while(cin>>total_num){
    while((total_num--)>0){
        vector<Point> v;
        int m,n,k;
        int peanuts=0;
        k=k-2;
        if(k<0){
            printf("%d\n",0);
            continue;
        }
        scanf("%d%d%d",&m,&n,&k);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int n;
                scanf("%d",&n);
                if(n>0){
                    Point p(i+1,j+1,n);
                    v.push_back(p);
                } 
            }
       //scanf("%d",&matrix[i][j]);
        /*
        printf("\n--------------------%d\n",v.size());
        for(int i=0;i<v.size();i++)
            printf("%d %d %d\n",v[i].peanuts,v[i].y,v[i].x);
            */
        sort(v.begin(),v.end(),cmp);
        /*
        printf("\n--------------------\n");
        for(int i=0;i<v.size();i++)
            printf("%d %d %d\n",v[i].peanuts,v[i].y,v[i].x);
        printf("\n--------------------\n");
        */
        for(int i=0;i<v.size();i++){
            if(i>0){
                if(k-1-v[i].y-(abs(v[i].y-v[i-1].y)+abs(v[i].x-v[i-1].x))>=0){
                    k=k-(abs(v[i].y-v[i-1].y)+abs(v[i].x-v[i-1].x))-1;
                    peanuts+=v[i].peanuts;
                }
                else break;
            }else{
                if(k-2*v[i].y-1>=0){
                    k=k-v[i].y-1;
                    peanuts+=v[i].peanuts;
                }
                else break;
            }
            // printf("steps:%d\n",k);
        }
        // printf("res:%d\n",peanuts);
        printf("%d\n",peanuts);
    }
}
    return 0;
}