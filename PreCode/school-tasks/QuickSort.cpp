#include<iostream>
using namespace std;
void sort(int* arr,int left,int right){
    int x=left,y=right;
    int cur=arr[(left+right)/2];
    do{
        while((arr[x]<cur)&&(x<right)) x++;
        while((arr[y]>cur)&&(left<y)) y--;
        if(x<=y){
            int temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
            x++;
            y--;
        }
    }while(x<=y);
    if(left<y) sort(arr,left,y);
    if(x<right) sort(arr,x,right);
}
int main() {
    int arr[]={1,3,5,7,9,2,4,6,8,4,5,7,8,2,3,9};
    // sort(arr,0,15);
    sort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        cout<<arr[i]<<"\t";
    return 0;
}
