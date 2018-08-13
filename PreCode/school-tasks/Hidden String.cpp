#include <iosteam>
using namespace std;
void handleString(char* s){
    static char* anniversary={"anniversary"};
    int count=0;
    int anniversary_index=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==anniversary[anniversary_index]){
            for(int n=i;n<strlen(s);n++){
                if(s[n]==anniversary[anniversary_index]){
                    anniversary_index++;
                }
                else{
                    break;
                }
            }
            count++;
        }
    }
    if(count==2&&anniversary_index==strlen(anniversary)-1){
        cout<<"YES";
    }

    else{
        cout<<"NO";
    }
}

int main(int argc, char const *argv[])
{
    int times;
    cin>>times;
    while(times-->0){
            char* s=new char[100];
            handleString(s);
    }
    system("pause");
    return 0;
}