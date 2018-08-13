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
    int index;       //结点在map中对应的位置
    int degree;     //结点的度
    int mark;   //结点的标记颜色
};
//bool cmp(NODE a,NODE b); //为排序算法提供的比较函数
//int fi1lcolor(int map[],int n);//着色函数
bool cmp(NODE a,NODE b){
    return a.degree>b.degree; //降序排列,使用大于号,用于S中物
}

int fillcolor(int map[],int n){
    int countMark = 0; //记录第一个使用的颜色号
    vector<int> mark; //颜色号集合
    vector<NODE> node; //图中结点集合
    node.resize(n);
    for(int i=0;i<n;i++){//统计图中每个结点的度
        node[i].degree=node[i].mark =0;
        node[i].index=i;
        for(int j=0;j<n;j++)
            if(map[i*n+j]==1)
                node[i].degree++;
    }
    sort(node.begin(),node.end(),cmp);
    for(int i=0;i<n;i++){//从结点集中取出结点
        for(int j=0;j<mark.size();j++){//从颜色集中取出颜色号
            if(node[node[i].index].mark ==0) node[node[i].index].mark=mark[j];//着色
            else break;
            for(int k=0;k<n;k++)//如果两个节点相邻而且颜色号相同,取消原颜色
                if(map[node[i].index*n+k]==1&& node[k].mark == node[node[i].index].mark)
                    node[node[i].index].mark =0;
        }
        if(node[node[i].index].mark ==0){//新增一个颜色号
            mark.push_back(++countMark);
            node[node[i].index].mark= mark.back();
        }
    }
    return countMark; //返回颜色数
}
int main(){
    int n=fillcolor(map,7);
    std::cout<<n<<"round is necessary to complete the game"<<std::endl;
    return 0;
}
