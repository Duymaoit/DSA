#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100];
bool use[100];
void result(){
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
}

void quaylui(int j){
	for(int i=1;i<=n;i++){
	 	if(use[i]==false){
	 	   a[j]=i;use[i]=true;
	 	   if(j==n) result();
	 	   else quaylui(j+1);
	 	   use[i]=false;
		}
	}
}

int main(){
    cin>>n;
    quaylui(1);
}


