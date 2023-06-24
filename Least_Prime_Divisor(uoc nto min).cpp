#include<bits/stdc++.h>
using namespace std;

int n=1000000;
int a[1000001];

void Least_Prime_Divisor(){
	 for(int i=0;i<=n;i++){
	 	 a[i]=i;
	 }
	 for(int i=2;i<=sqrt(n);i++){
	 	if(a[i]){
	 	   for(int j=i*i;j<=n;j+=i){
	 	   	    a[j]=min(a[j],i);
			}
		}
	 }
}

int main(){
    Least_Prime_Divisor();
    int n;cin>>n;
    for(int i=1;i<=n;i++){
    	cout<<a[i]<<" ";
	}
	return 0;
}


