#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

//aとbの最大公約数を返す
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

//拡張ユークリッドの互除法
//ax + by = gcd(a,b) = z となるような zが存在すればいい
int main() {
    ll x,y;
    extGCD(111,30,x,y);
    cout << x << " " << y << endl;
}   

