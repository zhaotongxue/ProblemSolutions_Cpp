#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define maxn 25
#define INF 0x7ffffff
#define manx 25
struct Edge {
    int from, to, cap, flow,cost;
    Edge(int from, int to, int cap, int flow,int cost) : from(from), to(to), cap(cap), flow(flow),cost(cost){};
};

struct MCMF {
    int n, m;
    std::vector<Edge> edges;  // all edges
    std::vector<int> G[maxn]; // adj edges
    int inq[manx];//is in queue?
    int d[maxn];//Bellman-Ford
    int a[maxn];              // flowed in
    int p[maxn];              // path
    void init(int n) {
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        edges.clear();
    }
    void addEdge(int from, int to, int cap,int cost) {
        edges.push_back(Edge(from, to, cap, 0,cost));
        edges.push_back(Edge(to, from, 0, 0,-cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellmanFord(int s, int t,int& flow,long long& cost) {
        for(int i=0;i<n;i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=0;
        p[s]=0;a[s]=INF;
            memset(a, sizeof(a), 0);
            std::queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty()) {
                int m = Q.front();
                Q.pop();
                inq[m]=0;
                for (int i = 0; i < G[m].size(); i++) {
                    Edge &e = edges[G[m][i]];
                    if (d[e.to]>d[m]+e.cost && e.cap > e.flow) {
                        d[e.to]=d[m]+e.cost;
                        p[e.to] = G[m][i];
                        a[e.to] = std::min(a[m], e.cap - e.flow);
                        if(!inq[e.to]){
                            Q.push(e.to);
                            inq[e.to]=1;
                        }
                    }
                }
            }
                if (d[t]==INF) return false;
                flow+=a[t];
                cost+=(long long)d[t]*(long long)a[t];
                for(int u=t;u!=s;u=edges[p[u]].from){
                    edges[p[u]].flow+=a[t];
                    edges[p[u]^1].flow-=a[t];
                }
                return true;
    }
};
