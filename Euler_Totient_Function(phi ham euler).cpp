#include<bits/stdc++.h>
using namespace std;

#define a 1000000007
#define ll long long 

ll Euler_Totient_Function(ll n){
	map<int,ll> mp;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			while(n%i==0){
				mp[i]++;
				n/=i;
			}
		}
	}
	if(n!=1) mp[n]++;
	ll sum=1;
	for(auto it: mp){
		sum*=pow(it.first,it.second-1)*(it.first-1);
	}
	return sum;
}

int main(){
	ll n;cin>>n;
	ll c=Euler_Totient_Function(n);
	cout<<c;
}


