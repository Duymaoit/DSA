#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long

void sang(ll l,ll r){
	bool p[r-l+1];
	for(ll i=0;i<=r-l;i++){
		p[i]=true;
	}
	for(ll i=2;i<=sqrt(r);i++){
		for(ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i){
			p[j-l]=false;
		}
	}
	for(ll i=0;i<=r-l;i++){
		if(p[i]==true&&i+l>=2) cout<<i+l<<" ";
	}
}

int main(){
   ll a,b;cin>>a>>b;
   sang(a,b);
}


