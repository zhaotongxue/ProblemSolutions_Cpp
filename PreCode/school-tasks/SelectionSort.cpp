#include <iostream>
using namespace std;
void exch(int* a,int x,int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}
void sort(int* a,int N){
    for(int i=0;i<N;i++){
        int min=i;
        for(int n=i+1;n<N;n++){
            if(a[min]<a[n]){
                min=n;
            }
        }
        exch(a,min,i);
    }
}
int main(int argc, char const *argv[])
{
    int arr[]={7,85,6,5,12,878,69,1,38,8,90,0,6};
    sort(arr,13);
    for(int i=0;i<13;i++)
        cout<<arr[i]<<"\t";
    /* code */
    return 0;
}