#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];
vector<pair<int,int>> edge;
set<int> adj[1005];

void bfs(int u,int s,int t){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visited[u]=true;
		for(int x: adj[u]){
			if(x==s&&u==t||x==t&&u==s) continue;
			if(!visited[x]){
				q.push(x);
			}
		}
	}
}

void init(){
	memset(visited,false,sizeof(visited));
	int n,m,cnt=0,result=0;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		edge.push_back({a,b});
		adj[b].insert(a);
		adj[a].insert(b);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			bfs(i,0,0);
			cnt++;
		}
	}
	for(auto it: edge){
		int x=it.first,y=it.second,tmp=0;
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				bfs(i,x,y);
				tmp++;
			}
		}
		if(tmp>cnt) result++;
	}
	cout<<"So canh cau la: "<<result<<endl;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
