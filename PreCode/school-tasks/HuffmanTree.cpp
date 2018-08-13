#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// const int INT_MIN=0x80000000;
// const int =0x7fffffff;
struct TNode
{
    int parent;
    int l;
    int r;
    int weight;
};
struct  twoInts
{
    int x;
    int y;
};
struct  TCode
{
    char data;
    //char code[128];
    string code;
    //bitset is better ,achieve later
};
class HuffmanTree {
public:
    void createHuffmanTree(int weights[], int num);
    void  createHuffmanCodeTable(char b[], int n);
    void Encode(char* s, char*& d, int n);
    void Decode(char*s, char* d, int n);
private:
    TNode* Tree;
    TCode* Codes;
};
void selectMin(TNode Tree[], twoInts* xy, int n) {
    // int x=0,y=1;
    // for(int i=0;i<n;i++){
    //     if(Tree[i].weight<Tree[x].weight&&)
    // }
    // int temp_index=0;
    // for(int i=0;i<n;i++){
    //     if(Tree[i].parent==-1){
    //         t[temp_index]=i;
    //         temp_index++;
    //         if(temp_index>1){
    //             break;
    //         }
    //     }
    // }
    // int temp=0;
    // int temp_index=0;
    // while(temp<=1){
    //     if(Tree[temp_index].parent==-1){
    //         t[temp]=temp_index;
    //         temp++;
    //     }
    //     temp_index++;
    // }
    int x = -1, y = -1;
    for (int i = 0; i<n; i++) {
        if (Tree[i].parent == -1&&(x==-1||Tree[i].weight<Tree[x].weight)) {
            x = i;
        }
    }
    // }
    for (int i = 0; i<n; i++) {
        if (Tree[i].parent == -1 && x != i&&(y==-1||Tree[i].weight<Tree[y].weight)) {
            y = i;
        }
    }
    if (x>y) {
        int t = x;
        x = y;
        y = t;
    }
    xy->x = x;
    xy->y = y;
    // cout<<t[0]<<"\t"<<t[1]<<endl;
    // return t;
    // for(int i=3;i<n;++){
    //     for(int n=0;n<2;n++){
    //         if(Tree[i].weight<Tree[t[n]].wight){

    //         }
    //     }
    // }
    // }
}
void HuffmanTree::createHuffmanTree(int weights[], int num) {
    Tree = new TNode[num * 2 - 1];
    for (int i = 0; i<num; i++) {
        Tree[i].weight = weights[i];
        Tree[i].l = Tree[i].r = Tree[i].parent = -1;
    }
    twoInts* xy = new twoInts();
    for (int i = num; i<num * 2 - 1; i++) {
        selectMin(Tree, xy, i);
        Tree[xy->x].parent = Tree[xy->y].parent = i;
        Tree[i].weight = Tree[xy->x].weight + Tree[xy->y].weight;
        Tree[i].l = xy->x;
        Tree[i].r = xy->y;
        Tree[i].parent = -1;
    }
}

void HuffmanTree::createHuffmanCodeTable(char b[], int n) {
    Codes = new TCode[n];
    for (int i = 0; i<n; i++) {
        Codes[i].data = b[i];
        string code = "";
        // TNode temp=Tree[i];
        int child = i;
        int parent = Tree[i].parent;
        while (parent!= -1) {
            if (child == Tree[parent].l) {
                code = "0" + code;
            } else { 
                code = "1" + code;
            }
            child = parent;
            parent = Tree[parent].parent;
        }
        cout << code << ":" << b[i] << endl;
        Codes[i].code = code;
    }
}
void HuffmanTree::Encode(char* s, char*& d, int n) {
    string ss="";
    while (*s != '\0') {
        for (int i = 0; i<n; i++) {
            if (*s == Codes[i].data) {
                string str(Codes[i].code);
                ss += str;
                cout << str << endl;
                break;
            }
        }
        s++;
    }
    //d = new char(ss.size() + 1);
    //cout << const_cast<char*>(ss.c_str()) << endl;
    d = const_cast<char*>(ss.c_str());
    //for (int i = 0; i < ss.size(); i++)
    //  d[i] = ss[i];
    //d[ss.size()] = '\0';
}
void HuffmanTree::Decode(char* s, char* ds, int n) {
    ds = new char(strlen(s)+1);
    while (*s != '\0') {
        int node_index = n * 2 - 2;
        while (Tree[node_index].l != -1) {
            if (*s == '0') {
                node_index = Tree[node_index].l;
            }
            else {
                node_index = Tree[node_index].r;
            }
            s++;
        }
        *ds=Codes[node_index].data;
        ds++;
    }
    ds[strlen(s)] = '\0';
    //ds = new char(d.size() + 1);
    //for (int i = 0; i < d.size(); i++)
    //  ds[i] = d[i];
    //ds[d.size()] = '\0';
    //cout << ds << endl;
}
int main() {
    int size = 0;
    cin >> size;
    int* weights = new int[size];
    char* s = new char[size];
    for (int i = 0; i<size; i++) {
        cin >> s[i] >> weights[i];
    }
    HuffmanTree hf;
    hf.createHuffmanTree(weights, size);
    hf.createHuffmanCodeTable(s, size);
    char* ss = new char(100);
    char* s_code=new char(100);
    cin >> ss;

    hf.Encode(ss, s_code, size);
    cout<<s_code << endl;
    hf.Decode(s_code, ss, size);
    cout <<ss << endl;
    return 0;
}