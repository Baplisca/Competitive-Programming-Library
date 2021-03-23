#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i < n; ++i)
#define exrep(i, a, b) for (ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<double>> vvd;
typedef vector<vector<string>> vvs;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
ll MOD = 998244353;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
void debug(T v)
{
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct mint
{
    long long x;
    mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += MOD - a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(long long t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const
    {
        return pow(MOD - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};

struct combination
{
    vector<mint> fact, ifact;
    combination(long long n) : fact(n + 1), ifact(n + 1)
    {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(long long n, long long k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
    //重複組み合わせ
    mint homogeneous(long long a, long long b)
    {
        long long n = a + b - 1;
        long long k = b;
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

//問題例　ABC167 E https://atcoder.jp/contests/abc167/tasks/abc167_e
signed main()
{
    gearup;
    ll n, m, k;
    cin >> n >> m >> k;
    mint res = 0;
    //ブロックの分け方
    //(n-1)C(i)
    //ブロックの色の塗り方
    //m*(m-1)^(n-i-1)
    vector<mint> p(n + 1, 1);
    rep(i, n) p[i + 1] = p[i] * (m - 1);
    combination C(n);
    for (ll i = 0; i <= k; i++)
    {
        mint block = C(n - 1, i);    //ブロックの分け方
        mint ans = p[n - i - 1] * m; //ブロックの色の塗り方
        mint tmp = block * ans;
        res = res + tmp;
    }
    out(res.x);
}