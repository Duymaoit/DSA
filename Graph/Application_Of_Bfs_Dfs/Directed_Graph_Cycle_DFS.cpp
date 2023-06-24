#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];
int color[10005];
int check=0;

void dfs(int u){
	color[u]=1;//xam
	for(int x: adj_edge[u]){
		if(color[x]==0) dfs(x);
		else if(color[x]==1) check=1;
	}
	color[u]=2;//den
}

void init(){
	memset(visited,false,sizeof(visited));
	memset(color, 0, sizeof(color));
	int n;cin>>n;
	for(int i=1;i<n;i++){
	    int a,b;
	    cin>>a>>b;
	    adj_edge[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(color[i]==0) dfs(i);
	}
	if(check) cout<<"Ton tai 1 chu trinh nao do";
	else cout<<"Khong ton tai chu trinh nao ca";
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
