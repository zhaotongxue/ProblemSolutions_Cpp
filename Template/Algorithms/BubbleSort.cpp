#include <iostream>
#include <ctime>
#include "StopWatch.h"
using namespace std;
static int mov=0;
static int cmp=0;
void reverse(int* arr,int len){
    int temp=0;
    for(int i=0;i<len/2;i++){
        temp=arr[i];
        arr[i]=arr[len-1-i];
        arr[len-1-i]=temp;
    }
}

void exch(int* a,int x,int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}
void sort(int* arr,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                cmp++;
                mov+=3;
                exch(arr,i,j);
            }
            cmp++;
        }
        // for(int j=i;j>=0&&arr[i]<arr[j];j--){
        //     temp=j;
        //     cmp++;
        //     mov+=3;
        //     exch(arr,i,j);
        // }
        // if(temp) cmp++;
    }
}
int main(int argc, char const *argv[])
{
    int* big_arr=new int[10000];
    srand((unsigned)time(NULL));
    for(int i=0;i<10000;i++)
        big_arr[i]=rand();
    stop_watch sw;
    sw.start();
    sort(big_arr,10000);
    sw.stop();
    printf("Random:\tcmp times:%d\tmove times:%d\t",cmp,mov);
    cout<<"time:"<<sw.elapsed()<<"ns"<<endl;

    cmp=0,mov=0;
    sw.restart();
    sort(big_arr,10000);
    sw.stop();
    printf("ASC:\tcmp times:%d\tmove times:%d\t",cmp,mov);
    cout<<"time:"<<sw.elapsed()<<"ns"<<endl;

    cmp=0,mov=0;
    reverse(big_arr,10000);
    sw.restart();
    sort(big_arr,10000);
    sw.stop();
    printf("DESC:\tcmp times:%d\tmove times:%d\t",cmp,mov);
    cout<<"time:"<<sw.elapsed()<<"ns"<<endl;
    delete[] big_arr;
    return 0;
}