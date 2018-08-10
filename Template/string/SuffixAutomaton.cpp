#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 300000;
const int maxm = 160000;
//SAM template
struct State{
    State *par;
    State *go[52];
    int val;//max当前状态能耐接受的串的最大长度
    int mi;//min 当前状态能接受的串的最短长度
    int cnt;//to count
    int right;//当前状态可以在多少个位置上出现
    void init(int _val=0):par(0),val(_val),cnt(0),mi(0),right(0){
        memset(go, 0, sizeof(go));
    }
    int calc(){//计算当前状态有多少个不同的串
        if(par==0)
            return 0;
        return val - par->val;
    }
};
State *root, *last, *cur;
State nodePool[maxn];
State* newState(int val=0){
    cur->init(val);
    return cur++;
}
void initSAM(){
    cur = nodePool;
    root = newState();
    last = root;
}
void extend(int w){
    State *p = last;
    State *np = newState(p->val + 1);
    np->right = 1;
    while(p&&p->go[w]==0){
        p->go[w] = np;
        p = p->par;
    }
    if(!p){
        np->par = root;
    }else{
        State *p = p->go[w];
        if(p->val==q->val-1){
            np->par = q;
        }else{
            State *nq = newState(p->val + 1);
            memcpy(nq->go, q->go, sizeof(q->go));
            nq->par = q->par;
            q->par = nq;
            np->par = nq;
            while(p&&p->go[w]==q){
                p->gp[w] = nq;
                p = p->par;
            }
        }
    }
    last = np;
}
int d[maxm];
State *b[maxn];
void topo{//parent 树的拓扑序
    int cnt = cur - nodePool;
    int maxVal = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i < cnt;i++){
        maxVal = max(maxVal, nodePool[i].val), d[nodePool[i].val]++;
    }
    for (int i = 1; i <= maxVal;i++)
        d[i] += d[i - 1];
    for (int i = 1; i < cnt;i++){
        b[d[nodePool[i].val]--] = &nodePool[i];
    }
    b[0] = root;
}
void gaoSamInit(){//求书SAM的附加信息
    State *p;
    int cnt = cnt->nodePool;
    for (int i = cnt - q; i > 0;i--){
        p = b[i];
        p->par->right += p->right;
        p->mi = p->par->val + 1;
    }
}
char s[maxm];
const int INF = 0x3f3f3ff3f;
int gao(char s[]){
    int ans = INF;
    int cnt = cur - nodePool;
    int len = strlen(s);
    int lcs = 0;
    State *p = root;
    for (int i = 0; i < len;i++){
        int son = s[i] - 'a';
        if(p->go[son]!=0){
            lcs++;
            p = p->go[son];
        }else{
            while(p&&p->go[son]==0)
                p = p->par;
                if(!p){
                    lcs = 0;
                    p = root;
                }else{
                    lcs = p->val + 1;
                    p = p->go[son];
                }
        }
        if(lcs>0)
            p->cnt++;
    }
    for (int i = cnt - 1; i > 0;i--){
        p = b[i];
        if(p->right==1&&p->cnt==1)
            ans = min(ans, p->mi);
        p->par->cnt += p->cnt;
    }
    return ans;
}