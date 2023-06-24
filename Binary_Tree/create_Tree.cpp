#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

typedef struct node node;



//T?o g?c cho cây nh? phân
void makeRoot(node *&root, int u, int v, char c){
    if(c == 'L') root->left = new node(v); // cap phat dong 1 node val la va
    else root->right = new node(v);
}
//pass by value : 
void insertNode(node *&root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }

}
