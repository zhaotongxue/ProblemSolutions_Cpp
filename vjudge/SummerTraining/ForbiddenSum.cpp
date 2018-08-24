#include <iostream>
#include <set>
// #define maxn 100000
#define DEBUG
using namespace std;
int main(int argc, char const *argv[])
{
    // int* dp[maxn];
    int array_size;
    cin>>array_size;
    int arr[array_size+1];
    for(int i=1;i<=array_size;i++){
        cin>>arr[i];
    }
    #ifdef DEBUG
    printf("this is array:----\n");
    for(int i=1;i<=array_size;i++) printf("%d ",arr[i]);
    printf("\n array print over\n");
    #endif
    int test_cases;
    cin>>test_cases;
    while(test_cases--){
        int a,b;
        cin>>a>>b;
        set<int> s;
        #ifdef DEBUG
            printf("%d\n",b-a+1);                              
        #endif
        for(int k=1;k<=b-a+1;k++){
            #ifdef DEBUG
            printf("%d\n",k);
            #endif
            s.insert(0);
            if(k==1){
                for(int i=0;i<b-a+1;i++){
                    s.insert(arr[i]);
                }
                continue;
            }
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=arr[a+i];
            }
            #ifdef DEBUG
            printf("%d - %d: %d\n",a,a+k,sum);
            #endif
            s.insert(sum);
            for(int i=k;i<b-a+1;i++){
                sum=sum+arr[a+i]-arr[a+i-k];
                #ifdef DEBUG
                printf("%d - %d: %d\n",a+i-k,a+i,sum);
                #endif
                s.insert(sum);
            }
            set<int>::iterator it=s.begin();
            set<int>::iterator tt=it;
            it++;
            for(;it!=s.end();it++,tt++){
                if((*tt-*it)>1){
                    printf("%d\n",*it+1);
                    break;
                }
            }
            if(it==s.end()){
                printf("%d\n",*tt+1);
            }
        }

    }
    return 0;
}