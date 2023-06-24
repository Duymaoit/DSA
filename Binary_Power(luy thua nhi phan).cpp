#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<bits/stdc++.h>
using namespace std;

#define a 1000000007

long long Binary_Power(long long n,long long m){
    if(m==0) return 1;
    ll x=Binary_Power(n,m/2);
    if(m%2==0){
       return (x%a*x%a)%a;
	}
	else return (x%a*x%a*n%a)%a;
}

ll reverse(ll n){
	ll m=0;
	while(n){
		m=m*10+n%10;
		n/=10;
	}
	return m;
}

int main(){
	ll n,m;cin>>n;
	m=reverse(n);
	cout<<Binary_Power(n,m);
}


