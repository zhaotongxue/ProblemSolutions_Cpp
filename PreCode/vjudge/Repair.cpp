#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int y,x;
    cin>>y>>x;
    int y1,x1,y2,x2;
    cin>>y1>>x1>>y2>>x2;
    if((y1+y2<=y&&x1<=x&&x2<=x)||(y1+y2<=x&&x1<=y&&x2<=y)||(x1+x2<=y&&y1<=x&&y2<=x)||(x1+x2<=x&&y1<=y&&y2<=y)||(y1+x2<=x&&y2<=y&&x1<=y)||(y1+x2<=y&&y2<=x&&x1<=x)||(y2+x1<=x&&y1<=y&&x2<=y)||(y2+x1<=y&&y1<=x&&x2<=x)) printf("YES");
    else printf("NO");
    for (int i = 0; i < str.length;i++){
        
    }
        return 0;
}