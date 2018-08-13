#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int numbers;
    double k;
    cin>>numbers>>k;
    int arr[numbers+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=numbers;i++)
        cin>>arr[i];
    for(int i=1;i<=numbers;i++){
        for(int t=i;arr[t]<arr[t-1]&&t>0;t--){
            int temp=arr[i];
            arr[i]=arr[t];
            arr[t]=temp;
        }
    }
    for(int current_index=1;current_index<=numbers;current_index++){
        int i=current_index;
        do{
            int min_index=i;
            for(int t=i-1;int(t/k)==int(i/k);t--){
                    if(arr[t]<arr[min_index]){
                        min_index=t;
                    }
            }
            for(int t=i+1;int(t/k)==int(i/k)&&t<=numbers;t++){
                    if(arr[t]<arr[min_index]){
                        min_index=t;
                    }
            }
            if(int(i/k)>0&&arr[min_index]<arr[int(i/k)]){
                int temp=arr[int(i/k)];
                arr[int(i/k)]=arr[min_index];
                arr[min_index]=temp;
            }else{
                break;
            }
        }while(i=int(i/k));
    }
    cout<<endl;
    for(int i=1;i<=numbers;i++)
        cout<<arr[i]<<"\t";
   return 0;
}

