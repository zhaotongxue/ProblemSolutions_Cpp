#include <iostream>
#include <queue>
#include <string.h>
#include <memory>
using namespace std;
int main()
{
    int k;
    cin>>k;
    queue<int>* queues[k];
    for(int i=0;i<k;i++)
        queues[i]=new queue<int>();
    int current_one;
    int count=0;
    int not_full_queues=0;
    //in
    while(cin>>current_one){
       int best_index=-1;
       for(int m=0;m<k;m++){
            if(queues[m]->empty()){
                not_full_queues=m;
                break;
            }
            else if(queues[m]->back()<current_one&&(best_index==-1||queues[m]->back()>queues[best_index]->back())){
                best_index=m;
            }
        }
        if(best_index!=-1){
            queues[best_index]->push(current_one);
            count++;
            continue;
        }
        else if(not_full_queues==k){
            cout<<"Illagal input,Application will exit"<<endl;
            return -1;
        }
        for(int i=0;i<k;i++){
            if(queues[i]->empty()){
                queues[i]->push(current_one);
                not_full_queues=i+1;
                count++;
                break;
            }
        }
}
//Out
queue<int>* outqueue=new queue<int>();
int min_index;
do{
    min_index=0;
    for(int i=0;i<k;i++)
        if(!queues[i]->empty()&&queues[i]->front()<queues[min_index]->front())
            min_index=i;
    outqueue->push(queues[min_index]->front());
    cout<<queues[min_index]->front()<<"\t";
    queues[min_index]->pop();
    count--;
    }while(count>0);
    for(int i=0;i<k;i++){
        delete queues[i];
    }
    delete outqueue;
    return 0;
}