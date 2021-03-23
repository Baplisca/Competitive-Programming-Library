#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=1000000007;

// a^b mod を計算する
ll mod_pow(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b & 1) return (a * mod_pow(a, b - 1, p)) % p;
    ll t = mod_pow(a, b / 2, p);
    return (t * t) % p;
}

ll mod_inv(ll a, ll p) { return mod_pow(a, p - 2, p); }
 
ll mod_comb(ll n, ll r, ll p) {
    ll tn = 1, tr = 1;
    for (int i = n; i > n - r; i--) {
        tn *= i;
        tn %= p;
    }
    for (int i = r; i > 0; i--) {
        tr *= i;
        tr %= p;
    }
    return tn * mod_inv(tr, p) % p;
}

int main(void){
    ll n;
    int a,b;
    cin >> n >> a >> b;
    if(n==2 && a ==1 && b==2)
        cout << '0' << endl;
    else{
        ll ans = mod_pow(2, n, MOD) - 1 - mod_comb(n, a, MOD) - mod_comb(n, b, MOD);
        while (ans < 0) ans += MOD;
        cout << ans << endl;
    }
}
