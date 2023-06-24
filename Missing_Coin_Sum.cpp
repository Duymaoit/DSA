#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll check=0;
    for(int i=0;i<n;i++){
        if(check+1<a[i]){
            cout<<check+1;
            return 0;
        }
        check+=a[i];
    }
    cout<<check+1;
}
