#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n,k,a[100],ok=1;

void init(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		a[i]=i;
	}
}

void sinh(){
	int i=k;
	while(i>=1&&a[i]==n-k+i){
		i--;
	}
	if(i==0) ok=0;
	else{
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[j-1]+1;
		}
	}
}

int main(){
	init();
	while(ok){
		for(int i=1;i<=k;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
    return 0;
}


