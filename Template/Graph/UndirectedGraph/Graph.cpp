#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
class Graph{
public:
Graph(int V):vectices(V){
    for (int i = 0; i < V;i++){
        adjs[i] = new std::vector<int>;
    }
};
  int V();
  int E();
  void addEdge(int v, int w);
//   std::string toString();
  std::vector<int>* adj(int v);
private:
    int vectices;
    int edges;
    std::vector<std::vector<int>*> adjs;
};
void Graph::addEdge(int v,int w){
    adjs[v]->push_back(w);
    adjs[w]->push_back(v);
}
int Graph::E(){
    return this->edges;
}
int Graph::V(){
    return this->vectices;
}
std::vector<int>* Graph::adj(int v){
    return adjs[v];
}
static int getDegree(Graph G,int v){
    return G.adj(v)->size();
}
/*
static int maxDegree(Graph G,int v){
    int degree = 0;
    for (int v = 0; v <=G.V();v++)
    {
        degree = std::max(degree, G.adj(v)->size());
    }
    return degree;
}
*/
// abcdefhaghligkl
static int numbersOfSelfLoops(Graph G){
    int count=0;
    for (int i = 0; i <=G.V();i++)
    {
        for (int w = 0; w <= G.adj(i)->size();w++)
        {
            if(i == G.adj(i)->at(w)) count++;
        }
    }
    return count / 2;
}
int main(int argc, char const *argv[])
{
    /* code */
    printf("started");
    return 0;
}

/*
std::string Graph::toString(){
    std::string s = V + " vectices" + E + " edges:\n";
    for (int v = 0; v <= G.V();v++)
    {
        s += v + " :";
        for (int w = 0; w < G.adj(V)->size();w++)
        {
            s += G.adj(V)[w]+ " ";
        }
        s += "\n";
    }
    return s;
}
int main(int argc, char const *argv[])
{
    return 0;
}

*/