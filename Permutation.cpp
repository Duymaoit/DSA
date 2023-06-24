#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n,ok=1,a[100];

void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}

void sinh(){
	int i=n-1;
	while(i>=1&&a[i]>a[i+1]){
		i--;
	}
	if(i==0) ok=0;
	else{
		for(int j=n;j>=1;j--){
			if(a[j]>a[i]){
				swap(a[i],a[j]);
				break;
			}
		}
		int l=i+1,r=n;
		while(l<r){
			swap(a[l],a[r]);
			l++;r--;
		}
	}
}

int main(){
    init();
    while(ok){
    	for(int i=1;i<=n;i++){
    		cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
    return 0;
}


