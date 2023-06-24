#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
 
vector<int> adj_edge[200005];
bool visited[200005];
int check=0,n;
int degree[10005];

void kahn(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(degree[i]==0) q.push(i);
	}
	vector<int>toppo;
	while(!q.empty()){
		int u=q.front();
		toppo.push_back(u);
		q.pop();
		for(int x: adj_edge[u]){
			if(!visited[x]){
			    degree[x]--;
			    if(degree[x]==0) q.push(x);
			}
		}
	}
	if(toppo.size()<n) cout<<"Do thi ko co chu trinh";
	else cout<<"Do thi co chu trinh";
}

void init(){
	memset(visited,false,sizeof(visited));
	memset(degree,0,sizeof(degree));
	cin>>n;
	for(int i=1;i<n;i++){
	    int a,b;
	    cin>>a>>b;
	    adj_edge[a].push_back(b);
	    degree[b]++;
	}
    kahn();
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
    init();
    return 0;
}
