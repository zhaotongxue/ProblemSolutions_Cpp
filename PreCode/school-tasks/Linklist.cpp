#include <iostream>
using namespace std;

//定义结点的结构
template <class T>
struct Node
{
	 T data;
     Node<T>  *next;
};

template <class T> 
class LinkList  
{
public:
	LinkList();    
	LinkList(T a[],int n);
	int Length();
	T Get(int);                        //查找
	int Locate(T);                      //定位
	void Insert(T,int);                  //插入
	T Delete(int);                    //删除
	~LinkList();
private:
	Node<T> *first;                      
};
template <class T>
int LinkList<T>::Length(){
    Node<T>* temp=first;
    int i=0;
    while((temp=temp->next)!=NULL)
        ++i;
    return i;
}
template <class T>
T LinkList<T>::Get(int pos) //找到返回指定位置的值
{ //初始化
	if (pos<1)
		throw "查找的位置>=1";

	Node<T> *p=first->next;
	int i=1;
	while(p!= NULL)
	{
		if (i==pos)
			return p->data;
		p = p->next;
		i++;
	}
	throw "输入的位置越界";

	return 0;
}
template <class T>int LinkList<T>::Locate(T x) //找到返回结点位置
{     //初始化
	Node<T> *p=first->next;
	int i=1;
	while(p!= NULL)
	{
		if (p->data == x)
			return i;
		p = p->next;
		i++;
	}
	return -1;
}
template <class T>
void LinkList<T>::Insert(T t,int pos) {
    if(pos>this->Length()+1)
        throw "Out of bound";

    Node<T>* new_node=new Node<T>;
    new_node->data=t;

    Node<T>* pre=first;
    while(pos-->1){
        pre=pre->next;
    }
    new_node->next=pre->next;
    pre->next=new_node;
}
template <class T>
T LinkList<T>::Delete(int n){
    if(n>this->Length())
        throw "Out of bound";
    
    Node<T>* item=first;
    while(n-->1){
        item=item->next; 
    }
    Node<T>* pre=item;
    item=item->next;
    pre->next=item->next;
    return item->data;
}

template <class T>
LinkList<T>::LinkList()
{
        first = new  Node<T>;
        first->next  = NULL;
}

//template <class T>
//LinkList<T>::LinkList(T a[], int n)
//{   //初始化头结点
//	  Node<T> *first = new  Node<T>;
//      Node<T> *r = first;
//      for (int i=0; i<n; i++)
//      {
//			//(1) 生成新结点
//			Node<T> *s=new Node<T>;  
//			s->data=a[i]; s->next = NULL;
//            //(2) 链接在尾结点后面
//			r->next = s;
//            //(3) 尾指针后移
//			r= s;
//      }
//
//}
template <class T>
LinkList<T>::LinkList(T a[], int n)
{   //初始化头结点
       first = new  Node<T>;
      first->next  = NULL;
      for (int i=0; i<n; i++)
      {
            //(1) 生成新结点
			Node<T> *s=new Node<T>;  
			s->data=a[i];
            //(2) 链接在头结点和首结点之间
			s->next = first->next;
			first->next  =s;
      }
}

template <class T>
LinkList<T>::~LinkList()
{     
	   while (first!=NULL )
       {
             Node<T> *p=first;             
             first = first->next;
             delete p;
       }
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};

	LinkList<int>  myList(a,10);

	cout<<myList.Locate(10)<<endl;
	cout<<myList.Get(1)<<endl;
                cout<<myList.Delete(1)<<endl;
                myList.Insert(2,1);
                cout<<myList.Get(1)<<endl;
                return 0;

}
