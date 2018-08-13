#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{   /*
    2 1 0
    3 2 3 4
    2 1 6
    2 0 5
    3 6 5 4
    2 2 0
    */
    /*
    int dist[7][7] = {
        { -1,-1,0,0,0,-1,0 },
        { -1,-1,-1,0,0,0,-1 },
        { 0,-1,-1,-1,-1,0,0 },
        { 0,0,-1,-1,0,0,0 },
        { 0,0,-1,0,-1,-1,0 },
        { -1,0,0,0,-1,-1,-1 },
        { 0,-1,0,0,0,-1,-1 }
    };
    */
    string s[7]={"ÌøÔ¶","Ìø¸ß","100m","200m","Ìú±ý","±êÇ¹","Ç¦Çò"};
    printf("Please enter the number of entries for each players and the number before each item player plays in order,split each one by space:\n");
    for(int i=0;i<7;i++){
        // printf("%d.%s\n",i,s[i]);
        cout<<i<<"."<<s[i]<<endl;
    }
    int dist[7][7];
    memset(dist,0,sizeof(int)*49);
    for(int i=0;i<7;i++)
        dist[i][i]==-1;
    for(int i=0;i<6;i++){
        int items;
        scanf("%d",&items);
        int item;
        int num[3]={-1,-1,-1};
        for(int t=0;t<items;t++){
            scanf("%d",&item);
            num[t]=item;
        }
        if(num[0]!=-1&&num[1]!=-1){
            dist[num[0]][num[1]]=-1;
            dist[num[1]][num[0]]=-1;
            if(num[2]!=-1){
                dist[num[0]][num[2]]=-1;
                dist[num[2]][num[0]]=-1;
                dist[num[1]][num[2]]=-1;
                dist[num[2]][num[1]]=-1;
            }
        }
    }
    int arr[7] = {0};
    int disabled[7];
    memset(&disabled, -1, sizeof(int) * 7);
    // int all_disabled = 0;
    queue<int>* q = new queue<int>;
    for (int i = 0; i<7; i++) {
        if (arr[i] != 0) continue;
        q->push(i);
        while (!q->empty()) {
            int start = q->front();
            q->pop();
            arr[start] = i + 1;
            for (int j = 0; j<7; j++) {
                if (dist[start][j] == -1 && disabled[j] == -1) {
                    disabled[j] = 0;
                }
            }
            for (int j = 0; j<7; j++) {
                if (dist[start][j] != -1 && disabled[j] == -1&&arr[j]==0) {
                    q->push(j);
                    break;
                }
            }
        }
        // all_disabled = 0;
        memset(&disabled, -1, sizeof(int) * 7);
    }
    for (int i = 0; i<7; i++) {
        bool b = false;
        for (int j = 0; j<7; j++) {
            if (arr[j] == i + 1) {
                b=true;
                cout << s[j] << "\t";
            }
        }
        if (b) cout << endl;
    }
    delete q;
    delete[] arr;
    delete[] disabled;
    delete[] s;
    return 0;
}