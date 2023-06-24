#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
char kq[100];
int n,k;
void result(){
	for(int i=1;i<=k;i++){
		cout<<kq[i];
	}
	cout<<endl;
}

void quaylui(int j){
	for(int i=0;i<=3;i++){
	 	kq[j]=s[i];
	 	if(j==k) result();
	 	else quaylui(j+1);
	}
}

int main(){
    cin>>n>>k;
    cin>>s;
    quaylui(1);
}


