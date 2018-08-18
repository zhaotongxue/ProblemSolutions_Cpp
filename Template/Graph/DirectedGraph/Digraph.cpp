#include <vector>
class Digraph
{
private:
    int Vi;
    int Ei;
    std::vector<int>* adjs;
public:
    Digraph(int);
    ~Digraph();
    int V();
    int E();
    void addEdge(int,int);
    std::vector<int> adj(int);
    Digraph reverse();
};

Digraph::Digraph(int V)
{
    this->Vi=V;
    this->Ei=0;
    this->adjs=new std::vector<int>[V];
}
Digraph::~Digraph()
{
    delete[] adjs;
}

int Digraph::E(){return this->Ei;}
int Digraph::V(){return this->Vi;}
void Digraph::addEdge(int v,int w){
    adjs[v].push_back(w);
    this->Ei++;
}
std::vector<int> Digraph::adj(int v){return adjs[v];}
Digraph Digraph::reverse(){
    Digraph R(this->Vi);
    for(int v=0;v<this->Vi;v++){
        for(int w:adjs[v]){
            R.addEdge(w,v);
        }
    }
    return R;
}
