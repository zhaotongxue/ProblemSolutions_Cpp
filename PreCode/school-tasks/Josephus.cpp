#include <iostream>
using namespace std;
class Node{
    private:
        int val;
    public:
        Node* next;
        Node(int);
        ~Node();
        int getVal();
};
Node::Node(int val){
    this->val=val;
};
Node::~Node(){
    delete this->next;
    this->next=NULL;
}
int Node::getVal(){
    return this->val;
};
void josephus(Node*,int);
int main()
{
    int length,interval;
    cin>>length>>interval;
    if(length<=1){
        cout<<"illeagl input"<<endl;
        return -1;
    }
    Node* start=new Node(1);
    Node* first=start;
    for(int i=2;i<=length;i++){
            first->next=new Node(i);
            first->next->next=NULL;
            first=first->next;
    }
    first->next=start;
    start=NULL;
    //Incoming first instead of start
    //because in josephus,it will move to next interval-1 times
    josephus(first,interval);
    return 0;
}
void josephus(Node* node,int interval){
        do{
            for(int i=0;i<interval-1;i++){
                node=node->next;
            }
            cout<<node->next->getVal()<<endl;
            node->next=node->next->next;
        }while(node->next!=node);
        cout<<node->getVal()<<endl;
}