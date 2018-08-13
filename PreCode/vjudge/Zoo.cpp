#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;
#define M 1000000007
#define L 1000000
#define seed 131
int getHash(char* s,int max_index,int sublen){
    int hash=0;
    for(int i=max_index-sublen;i<=max_index;i++){
        hash=hash*seed+s[i];
    }
    return hash;
}
void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen)  
    {  
        if (k == -1 || (p[j] == p[k]&&k<(j+1)/2))
        {  
            ++k;  
            next[j] = k;  
            ++j;  
        }  
        else   
        {  
            k = next[k];  
        }  
   }  
}  
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char str[L];
    while((n--)>0){
        cin>>str;
        int len=strlen(str),sum=1,temp=0;
        int next[len+1];
        GetNext(str,next);
        for(int x=1;x<len-1;x++){
            temp=next[x+1];
            sum*=(temp+1);
            /*
            if(temp>(x+1)/2){
                temp=0;
                int left_hash=0;
                for(int i=0;i<(x+1)/2;i++){
                    left_hash=left_hash*seed+str[i];
                    if(getHash(str,x,i)==left_hash)
                        temp++;
                    else 
                        break; 
                }
            }
            */
        }
        /*
        int last=0;
        int left_hash=0;
        for(int i=0;i<len/2;i++){
            left_hash=left_hash*seed+str[i];
            if(left_hash==getHash(str,len-1,i))
                last++;
            else break;
            // if(s.substr(0,i)==s.substr(len-i,len)) last++;
        }
            /*
        for(int i=0;i<(len-1)/2;i++){
            bool b=true;
            for(int t=0,c=i;t<=i;t++,c--){
                if(str[c]!=str[len-1-t]){
                    b=false;
                    break;
                }
            }
            if(!b) break;
            else last++;
        }
        // while(str[--len]==str[last]) last++;
        sum*=(last+1);
        */
        cout<<sum%M<<endl;
    }
    return 0;
}