#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[6];
int n;
void result(){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
}

void quaylui(int j){
	for(int i=0;i<=1;i++){
	 	a[j]=i;
	 	if(j==n) result();
	 	else quaylui(j+1);
	}
}

int main(){
    cin>>n;
    quaylui(1);
}


