#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[2005];
bool visited[200005];
int n;
int parent[1005];
int sz[1005];

void init(){
	cin>>n;
    for(int i=1;i<=n;i++){
    	parent[i]=i;
    	sz[i]=1;
	}
}

int find(int u){
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}

bool Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return false;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	parent[v]=u;
	return true;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
