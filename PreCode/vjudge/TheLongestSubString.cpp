//#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000005];
char s_new[2000010];
int p[2000010];
int Init(){
    int len=strlen(s);
    int j=0;
    s_new[j++]='$';
    s_new[j++]='#';
    //s_new[2*len+2]='\0';
    for(int i=0;i<len;i++){
        s_new[j++]=s[i];
        s_new[j++]='#';
    }
    s_new[j]='\0';
    // printf("%s\n",s_new);
    return j;
}
int Manacher(){
    int len=Init();
    int max_len=0;
    int id=0;
    int mx=0;
    for(int i=1;i<len;i++){
        if(i<mx){
            p[i]=min(p[id*2-i],mx-i);
        }else{
            p[i]=1;
        }
        //while(i-p[i]>=0&&i+p[i]<len&&s_new[i+p[i]]==s_new[i-p[i]]) p[i]++;
        while(s_new[i+p[i]]==s_new[i-p[i]]) p[i]++;
        if(mx<p[i]+i){
            id=i;
            mx=p[i]+i;
        }
        max_len=max(max_len,p[i]);
    }
    return max_len-1;
}
int main(){
    int n;

   // scanf("%d",&n);
    cin>>n;
    while(n--){
        //scanf("%s",s);
        cin>>s;
        //printf("%d\n",Manacher());
        cout<<Manacher()<<endl;
    }
    return 0;
}