#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int steps=0;
    int cases;
    cin>>cases;
    while(cases--){
        int x,y;
        cin>>x>>y;
        int mx=max(abs(x),abs(y));
        int mn=min(abs(x),abs(y));
        steps+=(2*mx)*(2*mx)-1;
        if(mx==-y){
            steps+=6*mx-1+mx+x;
        }
        else if(mx==y){
            steps+=2*mx-1+mx-x;
        }
        else if(mx==-x){
            steps+=4*mx-1+mx-y;
        }
        else{
            steps+=y+mx-1;
        }
        printf("%d\n",steps);
    }
    return 0;
}