#include<bits/stdc++.h>
using namespace std;

int n, X[100]; 
int cnt; 
bool final = false; 
void init(){
    cnt=1;
    X[1]=n;
}

void sinh(){
    int i = cnt;
    while(i >= 1 && X[i] == 1){
        --i;
    }
    if(i == 0){
      final = true;
    }
    else{
      int tmp = cnt - i + 1;
      --X[i];
     cnt = i;
     int q = tmp / X[i];
     int r = tmp % X[i];
     if(q != 0){
     for(int j = 1; j <= q; j++){
        X[i + j] = X[i];
     }
        cnt += q;
    }
    if(r!= 0){
      ++cnt;
      X[cnt]=r;
    }
    }
}
int main(){
    cin>>n;
    vector<vector<int>> v;
    init();
    while(!final){
        vector<int> v1;
    for(int i=1;i<= cnt;i++){
        v1.push_back(X[i]);
    }
    v.push_back(v1);
    sinh();
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
           cout<<v[i][j];
           if(j!=v[i].size()-1) cout<<"+";
        }
        cout<<endl;
    }
}


