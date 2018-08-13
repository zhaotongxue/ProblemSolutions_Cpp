#include <iostream>
using namespace std;
void exch(int* a,int x,int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}
void sort(int* a,int N){
    int h=0;
    while(h<N/3) h=h*3+1;
    while(h>0){
        for(int i=h;i<N;i++){
            for(int j=i;j>=h&&a[j]<a[j-h];j=j-h){
                exch(a,j,j-h);
            }
        }
        h=h/3;
    }
}
int main(int argc, char const *argv[])
{
    int arr[]={3,4,78,87,90,2,34,564,77,10};
    sort(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<"\t";
    /* code */
    return 0;
}