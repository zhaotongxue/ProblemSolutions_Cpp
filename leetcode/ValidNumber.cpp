#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        int lon=0,e=0,dot=0,res=-1;
        int len=s.length();
          for(int i=0;i<len;i++){
            if('0'>s[i]||s[i]>'9'){
                if(s[i]=='e'){
                    e++;
                    if(dot>0||i==len-1||res==0) return 0;
                }
                else if(s[i]=='.'){
                    dot++;
                    if(e>0){
                        return 0;
                    }
                }else if(s[i]==' '){
                    for(;i<len;i++){
                        if(s[i]!=' ') {
                            i--;
                            break;
                        }
                    }
                    if(lon>0) return 1;
                    else return 0;
                }
                if(e>1||dot>1) return 0;
            }
            else{
                res=res*1+(s[i]-'0');
            }

        }
        return 1;
                /*
                if(s[i]==' '){
                    if(lon>0){
                        for(int k=i;k<len;k++){
                            if(s[k]!=' '){
                                return 0;
                            }
                        }
                        return 1;
                    }
                    else {
                        while(i<len&&s[i]==' ') i++;
                        if(i==len||dot>0) return 0;
                        else i--;
                    }
                }
                else if(s[i]=='e'){
                    e++;
                    if(e>1||i==0||i==len-1||lon==0||dot!=0||(s[]==' '&&)){
                        return 0;
                    }
                }
                else if(s[i]=='.'){
                    dot++;
                    if(dot>1||e>0){
                        return 0;
                    }
                }else{
                    return 0;
                }
            }else{
                lon++;
            }
          }
          // cout<<"true"<<endl;
          if(lon) return 1;
            else return 0;
            */
    }
};
int main(){
    string s;
    s=". 1";
    Solution solution;
    cout<<solution.isNumber(s)<<endl;
}