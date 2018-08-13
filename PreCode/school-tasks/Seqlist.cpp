//开始编程
//目标：设计并实现一个通用类，完成XX管理系统需求
//
//1 数据类型T（任意）
//2 数据长度L（任意）
//3 通用操作（算法）：插入 删除 查找 输出
#include <iostream>
#include <cstring>
using namespace std;
struct INFO
{
	int ID;
	char PhoneNum[32];
	char Name[64];
	char MISC[256];
};

template <class T>
class SeqList
{
private:
	T *pData;
	int Size;//空间大小
	int Len;//有效数据长度
public:
	SeqList();
	~SeqList();
    void Insert(T e, int pos);//插入
	void Remove(int pos);//删除
	int Find(T e);//查找
	T GetData(int pos){return pData[pos];}//输出
	int GetLength(){return Len;}
};

template <class T>
int SeqList<T>::Find(T e){
    for(int i=0;i<Len;i++)
        if(pData[i].ID==e.ID)
            return i+1;
    return -1;
}
template <class T> SeqList<T>::SeqList()
{
	pData = NULL;
	Size = 0; 
	Len = 0;
}
template <class T> SeqList<T>::~SeqList()
{
	if (pData!=NULL)
	{
		delete []pData;
		pData = NULL;
	}
}

template <class T> 
void SeqList<T>::Insert(T e, int pos)//插入
{
   if (pos<1 || pos>Len+1)
	   throw "pos位置不合法";

   //动态内存开辟
   if (Len>=Size)
   {
	   //申请一个更大新空间
	   T* p = new T[Size+10+1];
	   //将原有数据拷贝到新空间
	   if (pData!=NULL)
			memcpy(p,pData,sizeof(T)*Size);
	   //删除原有空间
	   delete []pData;
	   pData = p;
	   Size = Size+10;
   }
   //插入
   //for (int i=Len+1 ;i>pos ;i--)
	  // pData[i] = pData[i-1];
   int i;
   for (i=Len ;i>=pos ;i--)
       pData[i+1] = pData[i];
   pData[pos] = e;
   Len++;

}

template <class T> 
void SeqList<T>::Remove(int pos)//删除
{
	if (Len == 0)
        throw 1;

	if (pos<1 || pos>Len)
		throw "位置不合法";

	for (int i=pos ; i<=Len-1 ;i++)
		pData[i] = pData[i+1];
	//for (int i=pos+1 ; i<=Len ;i++)
	//	pData[i-1] = pData[i];
    Len--;
}

 int  main()
 {
	SeqList<INFO> Contact;
	INFO s1={1,"13829279001","张三",""};
	INFO s2={2,"13829234002","李四",""};
                INFO s3={3,"12345678945","王五",""};
	try
	{
		cout<<"添加两条通信录"<<endl;
		Contact.Insert(s1,1);
		Contact.Insert(s2,1);
                                Contact.Insert(s3,2);
		//输出通信录的内容
		for (int i=1;i<=Contact.GetLength();i++)
		{
			INFO t = Contact.GetData(i);
			cout<<t.ID<<'\t'<<t.Name<<'\t'<<t.PhoneNum<<endl;
		}

		cout<<"删除第一条通信录"<<endl;
		Contact.Remove(1);
		//输出通信录的内容
                                for (int i=1;i<=Contact.GetLength();i++)
		{
			INFO t = Contact.GetData(i);
			cout<<t.ID<<'\t'<<t.Name<<'\t'<<t.PhoneNum<<endl;
		}
                                int pos1=Contact.Find(s3);
                                cout<<pos1<<endl;
     
	}
	catch(char* e)
	{
		cout<<e<<endl;
	}

                return 0;
 }

