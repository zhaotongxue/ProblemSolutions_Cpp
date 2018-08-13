#include <algorithm>
#include <vector>
#include <cmath>
#include <iosream>
using namespace std;
bool getRes(vector* v){
    sort(v->begin(),v->end());
    int old_size=-1;
    for(;old_size!=v->size();){
        old_size=v->size();
        for(int i=0;i<v->size()-1;i++){
            int temp=abs(v[i+1]-v[i]);
            if(temp==1) return 1;
            bool contained=false;
            for(int m=0;m<v->size();m++){
                if(v[m]==temp){
                    contained=true;
                    break;
                }
            }
            if(!contained) v->push_back(temp);
        }
    }
}
int* generate(int* arr,int min,int len,int max){
    for(int i=1;i<=len;i++){
        if()
    }
}
int main(int argc, char const *argv[])
{
    int a=2,b=4;
    int* arr=new int(3);
    for(int i=1;i<=4;i++){
        arr[i-1]=i;
    }
    vector<int>* v=new vector<int>;
    int res=0;
    for(int i)

    return 0;
}