#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node{
    int left,right;
    Node(){};
    Node(int l,int r):left(l),right(r){};
};
struct Point{
    int val;
    int pos;
    Point(){};
    Point(int v,int p):val(v),pos(p){};
    bool operator<(const Point& p) const{ return this->val<p.val;};
};
int main(){
    while(true){
        int nums,p,vsize;
        cin>>nums;
        if(nums==0) break;
        vector<Node> n;
        Point points[nums+1];
        for(int i=1;i<=nums;i++){
            cin>>p;
            Point point(p,i);
            points[i]=point;
        }
        stable_sort(points+1,points+nums+1);
        for(int i=1;i<=nums;i++){
                vsize=n.size();
                //找到现在的位置
                for(int vs=0;vs<vsize;vs++){
                    if(n[vs].right>=points[i].pos){//&&n[vs].left<=points[i].pos){
                        points[i].pos=n[vs].left+n[vs].right-points[i].pos;
                    }
                }
                if(i!=nums) printf("%d ",points[i].pos);
                else printf("%d",points[i].pos);
                Node node(i,points[i].pos);
                n.push_back(node);
        }
            delete[] points;
    }
    return 0;
}
