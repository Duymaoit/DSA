#include<bits/stdc++.h>
using namespace std;
#define ll long long


int Partition(int a[],int l ,int r){
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[r]);
	return i;
}

void QuickSort(int a[],int l,int r){
	if(l>=r) return ;
	int m=Partition(a,l,r);
	QuickSort(a,0,m-1);
	QuickSort(a,m+1,r);
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 1;
}
