//增广路算法
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define maxn 25
#define INF 0x7ffffff
struct Edge {
    int from, to, cap, flow;
    Edge(int from, int to, int cap, int flow)
        : from(from), to(to), cap(cap), flow(flow){};
};

struct EdmondsKarp {
    int n, m;
    std::vector<Edge> edges;  // all edges
    std::vector<int> G[maxn]; // adj edges
    int a[maxn];              // flowed in
    int p[maxn];              // path
    void init(int n) {
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        edges.clear();
    }
    void addEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    int maxFlow(int s, int t) {
        int flow = 0;
        for (;;) {
            memset(a, sizeof(a), 0);
            std::queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty()) {
                int m = Q.front();
                Q.pop();

                for (int i = 0; i < G[m].size(); i++) {
                    Edge &e = edges[G[m][i]];
                    if (!a[e.to] && e.cap > e.flow) {
                        p[e.to] = G[m][i];
                        a[e.to] = std::min(a[m], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t])
                    break;
            }
            if (!a[t])
                break;
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
