#include "Graph.cpp"
#include <iostream>
#include <cstring>
#include <algorithm>
class  DepthFirstSearch{
  private:
    bool* marked;
    int count;
    void dfs(Graph&, int);
  public:
    DepthFirstSearch(Graph& G, int s);
    bool marked(int w);
    int count();
}
DepthFirstSearch::DepthFirstSearch(Graph& G,int s){
    this->marked = new makred[G.V()];
    dfs(G, s);
}
void DepthFirstSearch::dfs(Graph& G,int s){
    marked[v]=true;
    count++;
    for(int w:G.V())
    if(!marked[w])
        dfs(G, w);
}
int DepthFirstSearch::count(){
    return count;
}
bool DepthFirstSearch::marked(int w){
    return marked[w];
}

