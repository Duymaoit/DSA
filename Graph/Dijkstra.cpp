#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<pair<int,int>> adj_edge[2005];
bool visited[200005];
int n,m;


void dfs(int u){
	visited[u]=true;
	for(int x: adj_edge[u]){
		if(!visited[x]) dfs(x);
	}
}

void Dijkstra(int u){
	vector<ll> distance(n+1,1e9);
	distance[u]=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,u});
	while(!q.empty()){
		pair<int,int> t=q.front();
		q.pop();
		int dis=t.first, u=t.second;
		if(dis>distance[u]) continue;
		for(auto x: adj_edge[u]){
			int v=it.first, w=it.second;
			if(distance[v]>distance[u]+w){
				distance[v]=distance[u]+w;
				q.push({distance[v],v});
			}
		}
	}
}

void init(){
	memset(visited,false,sizeof(visited));
	cin>>n,m;
	for(int i=1;i<=m;i++){
	    int x,y,w;
	    cin>>x>>y>>w;
	    adj_edge[x].push_back({y,w});
	    adj_edge[y].push_back({x,w});
	}
    Dijkstra(1);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
