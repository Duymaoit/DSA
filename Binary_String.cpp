#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ok=1;
int a[100];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
}

void sinh(){
	int i=n;
	while(i>=1&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0) ok=0;
	else a[i]=1;
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


