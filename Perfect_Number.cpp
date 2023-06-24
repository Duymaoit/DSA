#include<bits/stdc++.h>
#define ll long long
using namespace std;

int nto(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return n>=2;
}

int Perfect_Number(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(nto(i)){
			if(pow(2,i-1)*(pow(2,i)-1)==n){
				return 1;
				break;
			}
		}
	}
	return 0;
}

int main(){
    int n;cin>>n;
    if(Perfect_Number(n)) cout<<"YES";
    else cout<<"NO";
	return 0;
}
