#include <iostream>
using namespace std;
template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    bool checkEqual();
    int push(int dir,T t);
    int pop(int dir);
    int reSize(int);
    int incrementLo();
    int incrementHi();
    int getSize();
    void printSelf();
private:
    T* ts;
    int size; 
    int lo;
    int hi;
};
template<typename T>
void Stack<T>::printSelf(){
    for(int i=0;i<lo;i++){
        cout<<ts[i]<<endl;
    }
    for(int i=hi;hi<size;i++){
        cout<<ts[i]<<endl;
    }
}
template <typename T>
Stack<T>::Stack(){
    size=2;
    lo=-1;
    hi=2;
    ts=new T[size];
}
template<typename T>
int Stack<T>::push(int dir,T t){
    if(dir==1){
            lo=incrementLo();
            ts[lo]=t;
    }
    else{
            hi=incrementHi();
            ts[hi]=t;
    }
}
template<typename T>
int Stack<T>::pop(int pos){
    if(pos==1){
            if(lo-1>=-1){
                    lo--;
                    ts[lo+1]=0;
                    if(lo+1+size-hi<=size/2){
                        reSize(size/2);
                    }
                    return lo;
            }
            else{
                    if(lo+1+size-hi<=size/2){
                        reSize(size/2);
                    }
                return -1;
            }
    }
    else if(pos==2){
        if(hi+1<size){
            hi++;
            ts[hi-1]=0;
            if(lo+1+size-hi<=size/2){
                reSize(size/2);
            }
            return hi-1;
        }
        else{
            if(lo+1+size-hi<=size/2){
                reSize(size/2);
            }
            return -1;
        }
    }
}
template <typename T>
int Stack<T>::getSize(){
    return size;
}
template <typename T>
int Stack<T>::incrementLo(){
    lo++;
    checkEqual();
    return lo;
}
void checkEqual();
template<typename T>
int Stack<T>::incrementHi(){
    hi--;
    checkEqual();
    return hi;
}
template <typename T>
bool Stack<T>::checkEqual(){
    if(lo>=hi){
        reSize(size*2);
    }
}
template <typename T>
int Stack<T>::reSize(int new_size){
    //size=size*2;
    T* temp_t=new T[new_size];
    for(int i=0;i<=lo;i++)
        temp_t[i]=ts[i];
    for(int j=size-1,rank=1;j>=hi;j--,rank++)
        temp_t[new_size-rank]=ts[j];
    ts=temp_t;
    hi=new_size-size+hi;
    size=new_size;
}
template<typename T>
Stack<T>::~Stack(){
    delete ts;
    ts=NULL;
}
int main(){
    Stack<int> stack;
    stack.push(1,1);
    stack.push(2,1);
    stack.push(1,3);
    stack.push(2,3);
    stack.push(1,5);
    stack.printSelf();
    //stack.pop(1);
    stack.pop(1);
    stack.pop(2);
    cout<<"---------------"<<endl;
    stack.printSelf();
    return 0;
}