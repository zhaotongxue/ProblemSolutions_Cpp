#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int map[]={
    0,1,1,0,0,1,0,
    1,0,1,0,0,0,1,
    1,1,0,1,1,0,0,
    0,0,1,0,1,1,0,
    0,0,1,1,0,0,0,
    1,0,0,1,0,0,1,
    0,1,0,0,0,1,0
};
struct NODE{
    int index;       //�����map�ж�Ӧ��λ��
    int degree;     //���Ķ�
    int mark;   //���ı����ɫ
};
//bool cmp(NODE a,NODE b); //Ϊ�����㷨�ṩ�ıȽϺ���
//int fi1lcolor(int map[],int n);//��ɫ����
bool cmp(NODE a,NODE b){
    return a.degree>b.degree; //��������,ʹ�ô��ں�,����S����
}

int fillcolor(int map[],int n){
    int countMark = 0; //��¼��һ��ʹ�õ���ɫ��
    vector<int> mark; //��ɫ�ż���
    vector<NODE> node; //ͼ�н�㼯��
    node.resize(n);
    for(int i=0;i<n;i++){//ͳ��ͼ��ÿ�����Ķ�
        node[i].degree=node[i].mark =0;
        node[i].index=i;
        for(int j=0;j<n;j++)
            if(map[i*n+j]==1)
                node[i].degree++;
    }
    sort(node.begin(),node.end(),cmp);
    for(int i=0;i<n;i++){//�ӽ�㼯��ȡ�����
        for(int j=0;j<mark.size();j++){//����ɫ����ȡ����ɫ��
            if(node[node[i].index].mark ==0) node[node[i].index].mark=mark[j];//��ɫ
            else break;
            for(int k=0;k<n;k++)//��������ڵ����ڶ�����ɫ����ͬ,ȡ��ԭ��ɫ
                if(map[node[i].index*n+k]==1&& node[k].mark == node[node[i].index].mark)
                    node[node[i].index].mark =0;
        }
        if(node[node[i].index].mark ==0){//����һ����ɫ��
            mark.push_back(++countMark);
            node[node[i].index].mark= mark.back();
        }
    }
    return countMark; //������ɫ��
}
int main(){
    int n=fillcolor(map,7);
    std::cout<<n<<"round is necessary to complete the game"<<std::endl;
    return 0;
}
