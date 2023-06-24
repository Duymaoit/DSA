#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int data;
	struct node* next;
};

typedef struct node node;

node* makeNode(int x){
	node* newNode=new node();
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}

void browse_The_Linklist(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int count_Element_Linklist(node* head){
	int cnt=0;
	while(head!=NULL){
		head=head->next;
		cnt++;
	}
	return cnt;
}

void pushFront(node**head,int x){
	node* newNode=makeNode(x);
	newNode->next=(*head);
	(*head)=newNode;
}

void pushBack(node**head,int x){
	node* newNode=makeNode(x);
	node* tmp=*head;
	if((*head)==NULL){
		(*head)=newNode;
		return ;
	}
	else{
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}

void insertLinklist(node** head,int x,int k){
	int n=count_Element_Linklist(*head);
	if(k<1||k>n+1) return ;
	else if(k==1) pushFront(head,x);
	else if(k==n) pushBack(head,x);
	else{
		node* tmp=*head;
		node* newNode=makeNode(x);
		for(int i=1;i<k-1;i++){
			tmp=tmp->next;
		}
		newNode->next=tmp->next;
		tmp->next=newNode;
	}
}

void popFront(node**head){
	if((*head)==NULL) return;
	node*tmp=*head;
    (*head)=(*head)->next;
    free(tmp);
}

void popBack(node**head){
	if((*head)==NULL) return;
	node*tmp=*head;
	if(tmp->next==NULL){
		(*head)=NULL;
		free(tmp);
	}
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	node* last=tmp->next;
	tmp->next=NULL;
	free(last);
}

void pop(node**head,int k){
	int n=count_Element_Linklist(*head);
	if(k<1||k>n) return;
	if(k==1) popFront(head);
	else if(k==n) popBack(head);
	else{
		node* tmp=*head;
		for(int i=1;i<k-1;i++){
			tmp=tmp->next;
		}
		node* Erase=tmp->next;
		tmp->next=Erase->next;
		free(Erase);
	}
}

int main(){
    cout<<"          -----NHAP MENU CUA SU LUA CHON-----           "<<endl;
    cout<<"LC1: Duyet danh sach lien ket"<<endl;
    cout<<"LC2: Dem so luong node trong danh sach lien ket"<<endl;
    cout<<"LC3: Them vao dau danh sach lien ket"<<endl;
    cout<<"LC4: Them vao cuoi danh sach lien ket"<<endl;
    cout<<"LC5: Them vao giua danh sach lien ket"<<endl;
    cout<<"LC6: Xoa dau cua danh sach lien ket"<<endl;
    cout<<"LC7: Xoa cuoi cua danh sach lien ket"<<endl;
    cout<<"LC8: Xoa giua danh sach lien ket"<<endl;
    cout<<"LC0: Thoat chuong trinh"<<endl;
    node* head=NULL;
    while(true){
    	cout<<"Nhap lua chon: ";int lc;cin>>lc;
    	if(lc==1) browse_The_Linklist(head);
    	else if(lc==2) cout<<count_Element_Linklist(head)<<endl;
    	else if(lc==3){
    		int n;cin>>n;
    		for(int i=0;i<n;i++){
    			int x;cin>>x;
    			pushFront(&head,x);
			}
		}
		else if(lc==4){
			int n;cin>>n;
    		for(int i=0;i<n;i++){
    			int x;cin>>x;
    			pushBack(&head,x);
			}
		}
		else if(lc==5){
    		int x,k;cin>>x>>k;
    		insertLinklist(&head,x,k);
		}
		else if(lc==6){
			popFront(&head);
		}
		else if(lc==7){
			popBack(&head);
		}
		else if(lc==8){
			int k;cin>>k;
			pop(&head,k);
		}
		else break;
	}
	return 1;
}
