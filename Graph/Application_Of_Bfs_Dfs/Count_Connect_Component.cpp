#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];
int pa[10005];

void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visited[u]=true;
		cout<<u<<" ";
		for(int x: adj_edge[u]){
			if(!visited[x]){
				q.push(x);
				pa[x]=u;
			}
		}
	}
}

void init(){
	int n,cnt=0;cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj_edge[a].push_back(b);
		adj_edge[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			bfs(i);
			cnt++;
		}
	}
	cout<<"Tong so thanh phan lien thong: "<<cnt<<endl;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}