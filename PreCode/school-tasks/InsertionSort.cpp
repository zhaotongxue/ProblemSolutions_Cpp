#include <iostream>
using namespace std;
void exch(int* a,int x,int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}

void sort(int* a,int N)
{
    for (int i = 0; i < N; i++)
        for (int j = i; j > 0; j--)
            if (a[j]<a[j-1])
                exch(a, j, j-1);
            else break;

}
int main(int argc, char const *argv[])
{
    /* code */
    int arr[]={3,4,78,87,90,2,34,564,77,10};
    sort(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<"\t";

    return 0;
}