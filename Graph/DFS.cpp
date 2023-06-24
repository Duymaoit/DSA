#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];


void dfs(int u){
	visited[u]=true;
	cout<<u<<" ";
	for(int x: adj_edge[u]){
		if(!visited[x]) dfs(x);
	}
}

void init(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj_edge[a].push_back(b);
		adj_edge[b].push_back(a);
	}
	dfs(1);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
