#include <iostream>
#include <cstring>
using namespace std;
void print_subset(int arr[],int p,int n){
   if(p==n){
        for(int i=0;i<n;i++){
            if(arr[i]>0)
                printf("%d ",arr[i]);
        }
        printf("\n");
   }
   int arr1[n];
   memcpy(arr1,arr,n);
   arr1[p]=-1;
   print_subset(arr1,p+1,n);
   print_subset(arr,p+1,n);
}
int main(){
    int arr[]={1,2,3,4};
    print_subset(arr,0,4);
    return 0;
}