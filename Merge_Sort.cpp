#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans=0;

void Merge(int a[],int m,int l ,int r){
    vector<int> v1(a+l,a+m+1);
    vector<int> v2(a+m+1,a+r+1);
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size()){
    	if(v1[i]<=v2[j]){
    		a[l++]=v1[i++];
		}
		else{
			a[l]=v2[j];
			ans+=v1.size()-i;
			l++;j++;
		}
	}
	while(i<v1.size()){
		a[l++]=v1[i++];
	}
	while(j<v2.size()){
		a[l++]=v2[j++];
	}
}

void MergeSort(int a[],int l,int r){
	if(l>=r) return ;
	int m=(l+r)/2;  
	MergeSort(a,l,m);
	MergeSort(a,m+1,r);
	Merge(a,m,l,r);
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	MergeSort(a,0,n-1);
	cout<<ans;
	return 0;
}
