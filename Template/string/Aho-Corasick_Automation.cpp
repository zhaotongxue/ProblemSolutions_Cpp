#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 500005;

//data struct of ac automatic
struct node
{
    node *fail;
    node *next[26];
    int count;
    node() : fail(NULL), count(0)
    {
        memset(next, NULL, sizeof(next));
    }
} * q[maxn];
char keyword[51];
char str[maxn];
int head, tail;
//init tire tree
void insert(char *str, node *root)
{
    node *p = root;
    int i = 0, index;
    while (str[i] != '\0')
    {
        index = str[i] - 'a';
        if (p->next[index] == NULL)
            p->next[index] = new node();
        p = p->next[index];
        i++;
    }
    p->count++;
}
//construct fail pointer
void build_ac_automation(node *root)
{
    // queue<node *> q;
    root->fail = NULL;
    q[head++] = root;
    while (head != tail)
    {
        node *temp = q[tail++];
        node *p = NULL;
        for (int i = 0; i < 26; i++)
        {
            if (temp->next[i] != NULL)
            {
                if (temp == root)
                    temp->next[i]->fail = root;
                else
                {
                    p = temp->fail;
                    while (p != NULL)
                    {
                        if (p->next[i] != NULL)
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if (p == NULL)
                        temp->next[i]->fail = root;
                }
                q[head++] = temp->next[i];
            }
        }
    }
}
int query(node* root)
{
    node *p = root;
    int cnt = 0,index=0;
    for (int i = 0; i <strlen(str);i++){
        index = str[i] - 'a';
        while(p->next[index]==NULL&&p!=root)
            p = p->fail;
        p = p->next[index];
        if(p==NULL)
            p = root;
        node* temp=p;
        while(temp!=root){
            if(temp->count>=0){
                cnt+=temp->count;
                temp->count = -1;
            }else break;
           temp = temp->fail;
        }
    }
    return cnt;
}
    /*
        if(root->next[s[i]-'a']!=NULL){
            node *n = root->next[s[i] - 'a'];
            while(n!=root){
                cnt+=
            }
        }
    q.push(root);
    for (int i = 0; i < 51;i++){
        if(root->next[i]!=-1){
            root->next[i] = root;
            q.push(root->next[i]);
        }
    }
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        for (int i = 0; i < 51;i++){
            if(n->next[i]!=-1){
                if(n->next[i])
                q.push(n);
            }
        }
    }
    */
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    node *root = new node();
    for (int i = 0;i<n;i++){
        cin >> str;
        insert(str, root);
        build_ac_automation(root);
    }
    cin >> str;
    cout << query(root) << endl;
    return 0;
}
