#include "Graph.cpp"
// #include "DFS.cpp";
#include<algorithm>
#include <iostream>
#include <cstdlib>
#include <queue>
class DepthFirstPath{
    private:
      bool* marked;
      int* edgeTo;
      int s;
      void dfs(Graph& G, int s);
    public:
      DepthFirstPath(Graph& G, int s);
      bool hasEdgeTo(int v);
      queue<int> pathTo(int v);
}
DepthFirstPath::DepthFirstPath(Graph& G,int s){
    this->s = s;
    marked = new bool[G.V()];
    edgeTo = new int[G.V()];
    dfs(s);
}
void DepthFirstPath::dfs(Grap& G,int s){
    marked[s] = 1;
    for(int v:G.adj[s]){
        if(!marked[v])
            dfs(G, s;)
    }
}
queue<int> DepthFirstPath::pathTo(int s){
    queue<int> path;
    for (int x = v; x != s;x=edgeTo[x]){
        path.push(x);
    }
    path.push(v);
    return path;
}
bool DepthFirstPath::hasEdgeTo(int v){
    return marked[v];
}
