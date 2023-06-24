#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];
int parent[10005];
int check=0;

void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visited[u]=true;
		for(int x: adj_edge[u]){
			if(!visited[x]){
				parent[x]=u;
				q.push(x);
			}
			else{
				if(parent[x]!=u) check=1;
			}
		}
	}
}

void init(){
	memset(visited,false,sizeof(visited));
	int n,cnt=0,result=0;cin>>n;
	for(int i=1;i<=n;i++){
	    int a,b;
	    cin>>a>>b;
	    adj_edge[a].push_back(b);
	    adj_edge[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			parent[i]=i;
			bfs(i);
		}
	}
	if(check) cout<<"Ton tai 1 chu trinh nao do";
	else cout<<"Khong ton tai chu trinh";
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
