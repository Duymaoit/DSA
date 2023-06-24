#include<bits/stdc++.h>
using namespace std;

long long Lengedre_Fomula(long long n,long long p){
	 long long cnt=0;
	 int P=p;
	 while(P<=n){
	 	cnt+=n/P;
	 	P*=p;
	 }
	 return cnt;
}

int main(){
    long long n,p;cin>>n>>p; // ap dung cho p la nto
    cout<<Lengedre_Fomula(n,p);
	return 0;
}
