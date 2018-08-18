#include "Graph.cpp"
#include <queue>
#include<algorithm>
#include <iostream>
#include <cstdlib>
class DepthFirstPath{
    private:
      bool* marked;
      int* edgeTo;
      int s;
      void dfs(Graph& G, int s);
    public:
      DepthFirstPath(Graph& G, int s);
      bool hasEdgeTo(int v);
      std::queue<int> pathTo(int v);
};
DepthFirstPath::DepthFirstPath(Graph& G,int s){
    this->s = s;
    marked = new bool[G.V()];
    edgeTo = new int[G.V()];
    dfs(G,s);
}
void DepthFirstPath::dfs(Graph& G,int s){
    marked[s] = 1;
    std::vector<int>* vv=G.adj(s);
    for(int v:(*vv)){
        if(!marked[v])
            dfs(G, s);
    }
    // for(int i=0;i<G.adj[s]->size();i++){
    //     if(!marked[G.adj[s]->at(i)]){
    //         this->dfs(G,s);
    //     }
    // }
}
std::queue<int> DepthFirstPath::pathTo(int v){
    std::queue<int> path;
    for (int x = v; x != s;x=edgeTo[x]){
        path.push(x);
    }
    path.push(v);
    return path;
}
bool DepthFirstPath::hasEdgeTo(int v){
    return marked[v];
}
