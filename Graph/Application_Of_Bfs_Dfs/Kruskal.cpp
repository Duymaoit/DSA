#include<bits/stdc++.h>
using namespace std;
 
using ll= long long;
int n,m;
int parent[1005];
int sz[1005];
struct edge{
	int u,v;
	int w;
};
vector<edge> canh;
void init(){
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

void Nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,w;
		edge e;
		e.u=x;e.v=y;
		e.w=w;
		canh.push_back(e);
	}
}

bool cmp(edge a, edge b){
	return a.w< b.w;
}

void Kruskal(){
	vector<edge> mst;// tao cay khung cuc tieu
	int d=0;
	sort(canh.begin(),canh.end(),cmp);// sort danh sach canh
	for(int i=0;i<m;i++){
		if(mst.size()==n-1) break;
		edge e=canh[i];
		if(Union(e.u,e.v)){
			mst.push_back(e);
			d+=e.w;
		}
	}
	if(mst.size()!=n-1){
		cout<<"Do thi ko ton tai cay khung\n";
	}
	else{
		cout<<"Trong so cua cay khung la: "<<d<<endl;
		for(auto it: mst) cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	Nhap();
    init();
    return 0;
}
