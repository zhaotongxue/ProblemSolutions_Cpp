#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
const int MOD=1000000007;
const int MAX_LEN=1e6;
void GetNext(char* p,int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || p[j] == p[k]) {
            ++k;
            ++j;
            if(p[j]!=p[k])
                next[j] = k;
            else
                next[j]=next[k];
        }
        else 
        {
            k = next[k];
        }
    }
}
int main(){
    int cases=0;
    cin>>cases;
        while(cases--){
            char str[MAX_LEN];
            char pattern[MAX_LEN];
            cin>>str>>pattern;
            int len1=strlen(str);
            int len2=strlen(pattern);
            for(int i=0;i<len1/2;i++){
                char t=str[i];
                str[i]=str[len1-1-i];
                str[len1-i-1]=t;
            }
            for(int i=0;i<len2/2;i++){
                char t=pattern[i];
                pattern[i]=pattern[len1-1-i];
                pattern[len1-i-1]=t;
            }
            int next[len2];
            memset(next,-1,sizeof(next));
            GetNext(pattern,next);
            int i = 0;
            int j = 0;
            int sLen = len1;
            int pLen = len2;
            int res[len2];
            while (i < sLen)
            {
                if (j == -1) 
                {
                    i++;
                    j++;
                }
                else if(str[i] == pattern[j]){
                    res[j]++;
                    j++;
                    i++;
                }
                else
                {
                    j = next[j];
                    for(int t=0;t<j;t++)
                }
            }
            if(i>=sLen){
                break;
            }
            if (j == pLen){
                i=i-j+1;
                j=0;
            }
            for(int i=len2-1;i>0;i--)
            cout<<res[i]<<endl;
    }
return 0;
}