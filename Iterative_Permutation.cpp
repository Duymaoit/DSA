#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int kq[100];
void result(){
	for(int i=1;i<=n;i++){
		cout<<kq[i];
	}
	cout<<endl;
}

void quaylui(int j){
	for(int i=1;i<=n;i++){
	 	kq[j]=i;
	 	if(j==n) result();
	 	else quaylui(j+1);
	}
}

int main(){
    cin>>n;
    quaylui(1);
}


