#include <iostream>
#include <algorithm>
using namespace std;
int binary_search(const int arr[], int start, int end, int key) {
    int ret = -1;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else { 
            ret = mid;  
            break;
        }
    }
    return ret;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int res=0;
        int same=0;
        for(int i=0;i<n;i++){
            int tem_res=0;
            if(i+1<n&&arr[i]==arr[i+1]) {
                same++;
                i++;
            }
            for(int k=2;k<=arr[n-1]/arr[i];k++){
               int pos=binary_search(arr,i+1,n-1,arr[i]*k);
               if(pos!=-1){
                    while(arr[pos]==arr[pos-1]) tem_res++;
                    while(pos+1<n&&arr[pos]==arr[pos+1]) tem_res++;
               }
            }
            res+=(same+1)*(same+2)/2*tem_res;
            same=0;
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]%arr[i]==0) res++;
            }
        }
*/
        cout<<res<<endl;
    }
    return 0;
}