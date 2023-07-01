#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define m 1000000007
struct matrix {
    ll a[2][2];
    friend matrix operator *(matrix c, matrix d) {
        matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] += c.a[i][k] * d.a[k][j];
                    res.a[i][j]%=m;
                }
            }
        }
        return res;
    }
};

matrix powMode(matrix b, ll n) {
    if (n == 1) return b;
    matrix x = powMode(b, n / 2);
    if (n % 2 == 0) {
        return x * x;
    }
    else return x * x * b;
}

int main(){
    matrix b;
    b.a[0][0] = 1;
    b.a[0][1] = 1;
    b.a[1][0] = 1;
    b.a[1][1] = 0;
    ll n; cin >> n;
    matrix kp=powMode(b, n);
    cout<<kp.a[0][1]<<endl;
    return 0;
}
