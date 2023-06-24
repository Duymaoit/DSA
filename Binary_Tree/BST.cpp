#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct node{
	int val;
	node* left;
	node* right;
	node(int x){
		right=NULL;
		left=NULL;
		val=x;
	}
};

typedef struct node node;


bool search(node* root, int key){
	if(root==NULL) return false;
	else{
		if(root->val == key) return true;
		else if(root->val < key) return search(root->right,key);
		else return search(root->left,key);
	}
}

node* insert(node* root, int key){
	if(root==NULL){
		return new node(key);
	}
	if(key<root->val){
		root->left=insert(root->left,key);
	}
	else root->right=insert(root->right,key);
	return root;
}

void Inorder(node* root){
	if(root==NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

void Preorder(node* root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(node* root){
	if(root==NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->val<<" ";
}

node* minNode(node* root){
	node* temp=root;
	while(temp!=NULL && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

node* deleteNode(node* root, int key){
	if(root==NULL) return root;
	if(key < root->val) root->left=deleteNode(root->left, key);
	else if(key > root->val) root->right=deleteNode(root->right, key);
	else{
		if(root->left==NULL){
			node* tmp=root->right;
			delete root;
			return tmp;
		}
		else if(root->right==NULL){
            node* tmp=root->left;
            delete root;
            return tmp;
		}
		else{
			node*tmp= minNode(root->right);
			root->val=tmp->val;
			root->right=deleteNode(root->right,tmp->val);
		}
	}
	return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n;
    int a[n];
    for(int&x: a) cin>>x;
    cin>>m;
    node* root=NULL;
    for(int x: a){
    	root=insert(root,x);
	}
	root=deleteNode(root,m);
	Inorder(root);
    return 0;
}
