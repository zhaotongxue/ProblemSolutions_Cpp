#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
    std::vector<queue<int>*> queues;
    queues.push_back(new queue<int>());
    int current_one=0;
    cin>>current_one;
    queues[0]->push(current_one);
    while(cin>>current_one){
     int best_index=-1;
     for(int m=0;m<queues.size();m++)
        if(queues[m]->back()<current_one&&(best_index==-1||queues[m]->back()>queues[best_index]->back()))
            best_index=m;

        if(best_index!=-1){
            queues[best_index]->push(current_one);
        }
        else{
            queues.push_back(new queue<int>());
            queues[queues.size()-1]->push(current_one);
        }
    }
    cout<<queues.size()<<endl;
    for(int i=0;i<queues.size();i++)
        delete queues[i];
// int temp_count=count;
// auto_ptr<queue<int>*> outqueue=new queue<int>();
// do{
//     int min_index=0;
//     while(min_index<k&&queues[min_index]->empty())
//         min_index++;
//     for(int i=min_index;i<k;i++)
//         if(!queues[i]->empty()&&queues[i]->front()<queues[min_index]->front())
//             min_index=i;
//         outqueue->push(queues[min_index]->front());
//         queues[min_index]->pop();
//         count--;
//     }while(count>0);
//     while(!outqueue->empty()){
//         cout<<outqueue->front()<<endl;
//         outqueue->pop();
//     }
//     cout<<(temp_count==insert_num)<<endl;
//     delete[]  queues;
//     delete outqueue;
    return 0;
}