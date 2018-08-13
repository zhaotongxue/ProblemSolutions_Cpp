//��ʼ���
//Ŀ�꣺��Ʋ�ʵ��һ��ͨ���࣬���XX����ϵͳ����
//
//1 ��������T�����⣩
//2 ���ݳ���L�����⣩
//3 ͨ�ò������㷨�������� ɾ�� ���� ���
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
	int Size;//�ռ��С
	int Len;//��Ч���ݳ���
public:
	SeqList();
	~SeqList();
    void Insert(T e, int pos);//����
	void Remove(int pos);//ɾ��
	int Find(T e);//����
	T GetData(int pos){return pData[pos];}//���
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
void SeqList<T>::Insert(T e, int pos)//����
{
   if (pos<1 || pos>Len+1)
	   throw "posλ�ò��Ϸ�";

   //��̬�ڴ濪��
   if (Len>=Size)
   {
	   //����һ�������¿ռ�
	   T* p = new T[Size+10+1];
	   //��ԭ�����ݿ������¿ռ�
	   if (pData!=NULL)
			memcpy(p,pData,sizeof(T)*Size);
	   //ɾ��ԭ�пռ�
	   delete []pData;
	   pData = p;
	   Size = Size+10;
   }
   //����
   //for (int i=Len+1 ;i>pos ;i--)
	  // pData[i] = pData[i-1];
   int i;
   for (i=Len ;i>=pos ;i--)
       pData[i+1] = pData[i];
   pData[pos] = e;
   Len++;

}

template <class T> 
void SeqList<T>::Remove(int pos)//ɾ��
{
	if (Len == 0)
        throw 1;

	if (pos<1 || pos>Len)
		throw "λ�ò��Ϸ�";

	for (int i=pos ; i<=Len-1 ;i++)
		pData[i] = pData[i+1];
	//for (int i=pos+1 ; i<=Len ;i++)
	//	pData[i-1] = pData[i];
    Len--;
}

 int  main()
 {
	SeqList<INFO> Contact;
	INFO s1={1,"13829279001","����",""};
	INFO s2={2,"13829234002","����",""};
                INFO s3={3,"12345678945","����",""};
	try
	{
		cout<<"�������ͨ��¼"<<endl;
		Contact.Insert(s1,1);
		Contact.Insert(s2,1);
                                Contact.Insert(s3,2);
		//���ͨ��¼������
		for (int i=1;i<=Contact.GetLength();i++)
		{
			INFO t = Contact.GetData(i);
			cout<<t.ID<<'\t'<<t.Name<<'\t'<<t.PhoneNum<<endl;
		}

		cout<<"ɾ����һ��ͨ��¼"<<endl;
		Contact.Remove(1);
		//���ͨ��¼������
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

