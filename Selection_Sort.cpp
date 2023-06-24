#include<bits/stdc++.h>
using namespace std;
#define ll long long


void selectsort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int Min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[Min]) Min=j;
		}
		swap(a[i],a[Min]);
	}
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	selectsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
