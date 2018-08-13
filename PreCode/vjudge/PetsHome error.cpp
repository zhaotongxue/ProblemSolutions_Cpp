#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int pets[10005];
int pets_counts=0;
int dishappy=0;
queue<int> person;
int cases;
void get_pets(){
    if(!pets_counts) return; 
    if(person.empty()) return;
    int first=person.front();
    person.pop();
    if(pets[first]){
        pets[first]=0;
        pets_counts--;
    }else{
        for(int i=1;i<10000;i++){
            if(first-i>=0){
                if(pets[first-i]){
                    pets[first-i]=0;
                    pets_counts--;
                    dishappy+=i;
                    return;
                }
            }
            else if(first+i<10000){
                if(pets[first+i]){
                    pets[first+i]=0;
                    pets_counts--;
                    dishappy+=i;
                    return;
                }
            }
        }
    }
}
int main(){
    memset(pets,0,sizeof(pets));
    // scanf("%d",&cases);
    // getchar();
    cin>>cases;
    while(cases--){
        int identifity;
        int num;
        // scanf("%d%d",identifity,num);
        // getchar();
        cin>>identifity>>num;
        if(!identifity){
            pets[num]=1;
            pets_counts++;
        }else{
            person.push(num);
        }
        get_pets();
    }
    printf("%d",dishappy);
    return 0;
}
