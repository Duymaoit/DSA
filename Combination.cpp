#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
int kq[100];
void result(){
	for(int i=1;i<=k;i++){
		cout<<kq[i];
	}
	cout<<endl;
}

void quaylui(int j){
	for(int i=kq[j-1]+1;i<=n-k+j;i++){
	 	kq[j]=i;
	 	if(j==k) result();
	 	else quaylui(j+1);
	}
}

int main(){
    cin>>n>>k;
    quaylui(1);
}


