#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];


void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visited[u]=true;
		cout<<u<<" ";
		for(int x: adj_edge[u]){
			if(!visited[x]) q.push(x);
		}
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
	bfs(1);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
