#include <iostream>
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    Node* parent;
    int val;
    Node(Node* left,Node* right,Node* parent,int val):left(left),right(right),parent(parent),val(val){};
    int add(Node* n);
    int find(Node* n);
    bool operator==(const Node &n) const{return this->val==n.val;}
};
Node* search_val(Node*,int);
bool search(Node*,int);
Node* left_single_rotate(Node*);
Node* right_single_rotate(Node*);
void splay_tree(Node*,Node*);
void up(Node*,Node*);
Node* insert_node(Node*,Node*);
Node* search_val(Node* from,int val){
    if(from==NULL) return NULL;
    if(from->val==val) return from;
    else if(from->val>val) return search_val(from->left,val);
    else return search_val(from->right,val);
}
bool search(Node* root,int val){
    Node* n=search_val(root,val);
    if(n!=NULL&&n->val!=root->val){
        splay_tree(root,n);
        return true;
    }
    if(*n==*root) return true;
    return false;
}
Node* left_single_rotate(Node* n){
    Node* parent=n->parent;
    Node* newRoot=n->right;
    if(parent!=NULL){
        if(parent->left==n)
            parent->left=newRoot;
        else
            parent->right=newRoot;
    }
    newRoot->parent=parent;
    if(newRoot->left!=NULL) newRoot->left->parent=n;
    n->right=newRoot->left;
    n->parent=newRoot;
    newRoot->left=n;
    return newRoot;
}
Node* right_single_rotate(Node* n){
    Node* parent=n->parent;
    Node* newRoot=n->left;
    if(parent!=NULL){
        if(parent->left==n)
            parent->left=newRoot;
        else
            parent->right=newRoot;
    }
    newRoot->parent=parent;
    if(newRoot->right!=NULL) newRoot->right->parent=n;
    n->left=newRoot->right;
    n->parent=newRoot;
    newRoot->right=n;
    return newRoot;
}
void LL_rotate(Node* n){
    Node* next=n->left;
    right_single_rotate(n);
    right_single_rotate(next);
}
void RR_rotate(Node* n){
    Node* next=n->right;
    left_single_rotate(n);
    left_single_rotate(next);
}
void LR_rotate(Node* n){
    right_single_rotate(n->left);
    left_single_rotate(n);
}
void RL_rotate(Node* n){
    left_single_rotate(n->right);
    right_single_rotate(n);
}
void splay_tree(Node* n,Node* pos){
    while(n->left!=pos&&n->right!=pos){
        up(n,pos);
    }
    if(n->left==pos){
        right_single_rotate(n);
    }else{
        left_single_rotate(n);
    }
}
void up(Node* root,Node* pos){
    int i,j;
    Node* parent=pos->parent;
    Node* grandparent=parent->parent;
    i=grandparent->left==parent?-1:1;
    j=parent->left==pos?-1:1;
    if(i==1&&j==1){
        LL_rotate(grandparent);
    }else if(i==-1&&j==-1){
        RR_rotate(grandparent);
    }else if(i==-1&&j==1){
        LR_rotate(grandparent);
    }else{
        RL_rotate(grandparent);
    }
}
Node* insert_value(Node* root,int val){
    Node* find=search_val(root,val);
    if(find==NULL) return NULL;
    Node* n=new Node(NULL,NULL,NULL,val);
    if(root==NULL) root=n;
    else insert_node(root,n);
    return n;
}
Node* insert_node(Node* root,Node* n){
    if(n->val<root->val){
       if(root->left==NULL){
            root->left=n;
            n->parent=root;
            return n;
       }
       else insert_node(root->left,n);
    }else{
        if(root->right==NULL){
            root->right=n;
            n->parent=root;
            return n;
        }
        else insert_node(root->right,n);
    }
}
int main(){

    return 0;
}
