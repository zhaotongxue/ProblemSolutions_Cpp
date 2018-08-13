#include <iostream>
#include <cstring>
using namespace std;
void enumAll(int arr[],int n,int pos){
    if(pos==n){
        for(int i=0;i<n;i++){
            if(arr[i]>=0) printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    int t=arr[pos];
    enumAll(arr,n,pos+1);
    arr[pos]=-1;
    enumAll(arr,n,pos+1);
    arr[pos]=t;
}
int main(){
    int arr[]={1,2,3};
    enumAll(arr,3,0);
    return 0;
}