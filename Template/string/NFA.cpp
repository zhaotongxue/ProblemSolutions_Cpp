#include "../Graph/DirectedGraph/Digraph.cpp"
#include <string>
#include <stack>
#include <cstring>
class NFA
{
private:
    char* re;
    Digraph* G;
    int M;
public:
    NFA(std::string);
    ~NFA();
};

NFA::NFA(std::string exp)
{
    std::stack<int> ops;
    re=const_cast<char*>(exp.c_str());
    M=strlen(re);
    G=new Digraph(M+1);
    for(int i=0;i<M;i++){
        int lp=i;
        if(re[i]=='C'||re[i]=='|') ops.push(i);
        else if(re[i]==')'){
            int r=ops.top();
            ops.pop();
            if(re[r]=='|'){
                lp=ops.top();
                ops.pop();
                G->addEdge(lp,r+1);
                G->addEdge(r,i);
            }
            else lp=r;
        }
        if(i<M-1&&re[i+1]=='*'){
            G->addEdge(lp,i+1);
            G->addEdge(i+1,lp);
        }
        if(re[i]=='('||re[i]=='*'||re[i]==')'){
            G->addEdge(i,i+1);
        }
    }
}

NFA::~NFA()
{
    delete G;
    delete[] re;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
