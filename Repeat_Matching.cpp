#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int n,k,final=0;
int a[11];

void khoitao(){
    for(int i=1;i<=k;i++){
        a[i]=1;
    }
}

void sinh(){
    int i=k;
    while(i>=1&&a[i]==n) i--;
    if(i==0) final=1;
    else{
        a[i]++;
        for(int j=i+1;j<=k;j++){
            a[j]=1;
        }
    }
}

int main(){
    cin>>n>>k;
    khoitao();
    while(!final){
        for(int i=1;i<=k;i++){
             cout<<a[i];
        }
        cout<<endl;
        sinh();
    }
    return 0;
}



