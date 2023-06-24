#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[2005];
vector<int> transpose_adj_edge[2005];
bool visited[200005];
int n;
stack<int> st;

void dfs(int u){
	visited[u]=true;
	for(int x: adj_edge[u]){
		if(!visited[x]) dfs(x);
	}
	st.push(u);
}

void dfs1(int u){
	visited[u]=true;
	for(int x: transpose_adj_edge[u]){
		if(!visited[x]) dfs1(x);
	}
}

void kosaraju(){
	for(int i=1;i<=n;i++){
		if(!visited[i]) dfs(i);
	}
	memset(visited,false,sizeof(visited));
	int scc=0;
	while(!st.empty()){
		int u=st.top();
		st.pop();
		if(!visited[u]){
			scc++;
			dfs1(u);
		}
	}
	cout<<"Strong_Connected_Component by kosaraju: "<<scc<<endl;
}

void init(){
	memset(visited,false,sizeof(visited));
	cin>>n;
	for(int i=1;i<n;i++){
	    int a,b;
	    cin>>a>>b;
	    adj_edge[a].push_back(b);
	    transpose_adj_edge[b].push_back(a);
	}
    kosaraju();
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
