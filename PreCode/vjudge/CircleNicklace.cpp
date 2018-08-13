#include <iostream>
#include <cstring>
using namespace std;
void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen)  
    {  
        if (k == -1 || p[j] == p[k])
        {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  
        else   
        {  
            k = next[k];  
        }  
   }  
} 
int main(){
    int n;
    cin>>n;
    while((n--)>0){
        char str[100005];
        int next[100005];
        scanf("%s",str);
        getchar();
        int len=strlen(str);
        GetNext(str,next);
        /*
        for(int i=0;i<len+1;i++)
            cout<<next[i]<<endl;
            */
        // if(next[len]<=len/2){
            // cout<<len-next[len]*2<<endl;
        // }
        // else
        // cout<<len-next[len]<<endl;
        /*
        if(len==next[len]) cout<<0<<endl;
        else if(next[len]<=len/2) cout<<len-2*next[len]<<endl;
        else if(len/2<next[len]<len/3*2) cout<<4*Nex
        else if(len/3*2<next[len]) cout<<4*next[len]-3*len<<endl;
        else cout<<len-next[len]-len%(len-next[len])<<endl;
        */
        //原来他们有个名字叫做最小循环节
        //next[len]=0 len=len，循环了一次，要排除
        //猜了个坑，scanf之后要getchar一下
        if(next[len]!=0&&len%(len-next[len])==0) printf("0\n");
        else printf("%d\n",len-next[len]-len%(len-next[len]));
    }
    return 0;
}