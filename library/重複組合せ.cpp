#include <bits/stdc++.h>
using namespace std;

#define int long long
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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
ll MOD = 1e9 + 7;
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
ll pcount(ll x) { return __builtin_popcountll(x); }
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

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
//重複組み合わせ
//ABC156 E Roaming https://atcoder.jp/contests/abc156/tasks/abc156_e
signed main()
{
    gearup;
    ll n, k;
    cin >> n >> k;
    combination C(n);
    mint res = 0;
    //0になる家の数を全探索
    rep(i, min(n, k + 1))
    {
        //残りの家
        int other = n - i;
        res += C(n, i) * C.homogeneous(other, i); //C.homogeneous(a,b): bを残りのaに振り分ける重複組み合わせ
    }
    out(res.x);
}
