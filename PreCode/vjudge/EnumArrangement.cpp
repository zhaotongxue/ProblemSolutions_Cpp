#include <iostream>
#include <cstring>
using namespace std;
void enumAll(int arr[],int pos,int size,bool p){
    if(p) cout<<arr[pos]<<"\t";
    // for(int i=pos;i<size;i++){
    if(pos+1<size){
        enumAll(arr,pos+1,size,0);
        enumAll(arr,pos+1,size,1);
    }
    cout<<endl;
    // for(int i=start+1;i<end;i++)
    //     cout<<arr[i]<<"\t";
}
int main(){
    int arr[]={1,2,3,4,5};
    cout<<"enum from 1:"<<endl;
    enumAll(arr,0,5,1);
    cout<<"enum from 0:"<<endl;
    enumAll(arr,0,5,0);

    return 0;
}