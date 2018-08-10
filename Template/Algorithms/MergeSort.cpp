#include <iostream>
using namespace std;
void merge(int*,int*,int,int,int);
void sort(int* a,int* aux,int lo,int hi){
    if(lo>=hi) return;
    int mid=lo+(hi-lo)/2;
    sort(a,aux,lo,mid);
    sort(a,aux,mid+1,hi);
    merge(a,aux,lo,mid,hi);

}
void merge(int* a, int* aux, int lo, int mid, int hi) {
    int i=lo;
    int j=mid+1;
    for(int k=lo;k<=hi;k++)
        aux[k]=a[k];
    for(int k=lo;k<=hi;k++){
        if (i>mid)                                      a[k]=aux[j++];
        else if (j>hi)                                  a[k]=aux[i++];
        else if(aux[i]<=aux[j])    a[k]=aux[j++];
        else                                            a[k]=aux[i++];
    }
}
int main(){
    int arr[]={3,4,78,87,90,2,34,564,77,10};
    int arr2[10];
    sort(arr,arr2,0,9);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<"\t";

    return 0;
}