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
		for(int x: adj_edge[u]){
			if(!visited[x]){
				q.push(x);
				pa[x]=u;
			}
		}
	}
}

void init(){
	memset(visited,false,sizeof(visited));
	int n,cnt=0,result=0;cin>>n;
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
	for(int i=1;i<=n;i++){
		memset(visited,false,sizeof(visited));
		visited[i]=true;
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(!visited[j]){
				tmp++;
				bfs(j);
			}
		}
		if(tmp>cnt) result++;
	}
	cout<<"So dinh tru la: "<<result<<endl;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
