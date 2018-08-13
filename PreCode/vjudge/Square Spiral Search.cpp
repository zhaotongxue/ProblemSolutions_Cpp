#include <iostream>

using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int x,y;
        int res=0;
        cin>>x>>y;
        int width=max(abs(x),abs(y));
        res+=(2*max(abs(x),abs(y))-1)*(2*max(abs(x),abs(y))-1)-1;
        if(x>=0&&y>=0){
            res+=y+width-1+width-x;
        }else if(x<0&&y>=0){
            res+=3*width-1;
            res+=abs(x)+width-y;
        }else if(x<0&&y<0){
            res+=5*width-1;
            res+=abs(y)+width-abs(x);
        }else{
            if(y==-width) res+=7*width-1+abs(x);
            else{
                res+=width-1-abs(y);
            }
        }
        printf("%d\n",res+1);
    }
    return 0;
}