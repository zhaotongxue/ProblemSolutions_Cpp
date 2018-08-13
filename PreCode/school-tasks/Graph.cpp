#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#define MAX 0x777777
using namespace std;
class Edge{
    int fromV;
    int endV;
    int weight;
}
class Graph{
private:
    int V;
    int E;
public:
    vector<vector<int>> adj;
    vector<Edge> edges;
    Graph();
    int getV();
    int getE();
    void addEdge(int,int,int);
    ~Graph();
};
Graph::Graph(){
    int vs,es;
    scanf("%d%d",&vs,&es);
    this->V=vs;
    this->E=0;
    for(int i=0;i<vs;i++){
        vector<int> my_vector;
        adj.push_back(my_vector);
    }
    int v,w,p;
    for(int i=0;i<es;i++){
        scanf("%d%d%d",&v,&w,&p);
        addEdge(v,w,p);
    }
}
Graph::~Graph(){
}
void Graph::addEdge(int v,int w,int p){
        adj[v].push_back(w);
        adj[w].push_back(v);
        Edge e;
        e.fromV=v;
        e.endV=w;
        e.weight=p;
        edges.push_back(e);
        E++; 
}
int Graph::getV(){return V;}
int Graph::getE(){return E;}

class DepthFirstSearch{
private:
    bool* marked;
    int* edgeTo;
    int count;
    int s;
    void dfs(Graph&,int);
public:
    DepthFirstSearch(Graph&,int);
    bool isMarked(int);
    int getCount();
    bool hasPathTo(int d);
    stack<int>* pathTo(int d);
};
DepthFirstSearch::DepthFirstSearch(Graph& G,int s){
    marked=new bool(G.getV());
    edgeTo=new int(G.getV());
    this->s=s;
    dfs(G,s);
}
void DepthFirstSearch::dfs(Graph& G,int v){
    marked[v]=true;
    count++;
    for(int i=0;i<G.adj[v].size();i++)
        if(!marked[i]) {
            edgeTo[i]=v;
            dfs(G,i);
        }
}
bool DepthFirstSearch::isMarked(int i){return marked[i];}
int DepthFirstSearch::getCount(){return count;}
bool DepthFirstSearch::hasPathTo(int d){return marked[d];}
stack<int>* DepthFirstSearch::pathTo(int d){
    if(!hasPathTo(d)) return NULL;
    stack<int>* s=new stack<int>;
    for(int i=d;d!=this->s;i=edgeTo[i])
        s->push(i);
    s->push(this->s);
    return s;
}
class BreadthFirstSearch{
private:
    int* marked;
    int s;
public:
    int* edgeTo;
    BreadthFirstSearch(Graph&,int);
    void bfs(Graph&,int);
    bool isMarked(int);
    bool getCount();
    bool hasPathTo(int v);
    stack<int>* pathTo(int v);
};
BreadthFirstSearch::BreadthFirstSearch(Graph& G,int v){
    marked=new int(G.getV());
    edgeTo=new int(G.getV());
    this->s=s;
    bfs(G,v);
}
void BreadthFirstSearch::bfs(Graph& G,int s){
    queue<int> queue;
    marked[s]=true;
    while(!queue.empty()){
        int v=queue.front();
        queue.pop();
        for(int i=0;i<G.adj[v].size();i++){
            if(!marked[i]){
                edgeTo[i]=v;
                marked[i]=true;
                queue.push(i);
            }
        }
    }

}
bool BreadthFirstSearch::hasPathTo(int v){return marked[v];}
stack<int>* BreadthFirstSearch::pathTo(int v){
    if(!hasPathTo(v)) return NULL;
    stack<int>* s;
    for(int i=v;v!=this->s;i=edgeTo[i])
        s->push(i);
    s->push(this->s);
    return s;

}
class Prim{
private:
    // int* marked;
    int* adjvex;
    int* lowcast;
public:
    Prim(Graph&);
    int minium(Graph&,int*);
    vector<int>* path;
    vector<int>* getPath();
};
Prim::Prim(Graph& G){
    for(int i=0;i<G.getV();i++){
        adjvex[i]=0;
    }
    for(int i=0;i<G.getE();i++){
        if(G.edges[i].fromV==0){
            
        }
    }
    path=new vector<int>;
    for(int i=0;i<G.getV();i++){
        int k=minium(G,lowcast);
        path.push_back(k);
        for(int j=0;j<G.adj[k].size();j++){
            if(lowcast[j]!=0&&G.weights[i][j]<lowcast[j]){
                lowcast[j]=G.weights[i][j];
                adjvex[j]=k;
            }
        }
    }
}
vector<int>* getPath(){return path;}
int Prim::minium(Graph& G,int* lowcast){
    int min=MAX;
    int k=0;
    for(int i=0;i<G.getV();i++){
        if(lowcast[i]!=0&&lowcast[i]<min){
            min=lowcast[i];
            k=i;
        }
    }
    return k;
}
class Edge{
    int fromV;
    int endV;
    int weight;
};
class Kruskal{
public:
    vector<int> edgeList
    Kruskal(Graph&,int);
    void sort(Graph&);
};
void Kruskal::sort(Graph& G){
    int[MAX] temp={0};
    for(int i=0;i<G.getV();i++){
        for(int j=0;j<G.adj[j].size();j++){
            if()
        }
    }
}
int main(){

}