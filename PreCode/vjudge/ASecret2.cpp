#include <iostream>
#include <cstring>
using namespace std;
const int NUM=1000000007;
char s[1000005];
void getNext(char* pattern,int next[]){
	int len=strlen(pattern);
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<len-1){
		if(k==-1||p[j]==p[k]){
			++k;
			++j;
			if(p[j]!=p[k]) next[j]==k;
			else next[j]=next[k];
		}else{
			k=next[k];
		}
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		cin>>p;
		int len=strlen(p);
		int sum=0;
		for(int i=0;i<len;i++){
			int inner=0;
			char subpattern[len-i];
			int arr[len-i];
			memset(arr,-1,sizeof(arr));
			memcpy(subpattern,p+i,sizeof(subpattern));
			getNext(subpattern,arr);
			int m=0,n=0,sLen=strlen(s),pLen=strlen(subpattern);
			while(m<sLen){
				if(n==-1||s[n]==subpattern[m]){
					m++;
					n++;
					if(n==pLen){
						inner++;
						n=0;
					}
				}else{
					n=arr[n];	
				}
			}
			cout<<"N"<<len-i<<":"<<inner<<endl;
			sum+=inner*(len-i);
		}
		cout<<sum<<endl;
	}
	return 0;
}
