#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
#define ll long long 
#define m 1000000007

ll gapDoi(ll k,int n) {
    if (k == pow(2, n) ) return n+1;
    else if (k < pow(2, n) ) return gapDoi(k, n - 1);
    else return gapDoi(k - pow(2, n), n - 1);
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    cout << gapDoi(k,n) << endl;
    return 0;
}
