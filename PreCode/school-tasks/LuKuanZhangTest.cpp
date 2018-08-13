#include <iostream>
#include <cstring>
using namespace std;
    int main()
    {
        int Size=3;
        int* data=new int[Size];
        data[0]=0;
        data[1]=1;
        data[2]=2;
        data=(int*)realloc(data,Size+1);
        data[Size++]=3;
        cout<<Size<<endl;
        cout<<endl;
        for(int i=0;i<Size;i++) 
            cout<<data[i]<<endl;
        /*
        int* a={1,2,3,4,5,6,7,8,9};
        realloc(a,20);
        for(int index=0;index<20;index++)
            cout<<a[index]<<endl;
          */  
        return 0;
    }
