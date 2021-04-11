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
ll pcount(ll x) { return __builtin_popcountll(x); }
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

//素因数分解
map<int, int> decompositPrime(ll n)
{
    map<int, int> ans;
    ll num = 2;
    while (n >= num * num)
    {
        if (n % num == 0)
        {
            ans[num]++;
            n /= num;
        }
        else
        {
            num++;
        }
    }
    ans[n]++;
    return ans;
}
//分子と分母を素因数分解してけた溢れを防ぐ
ll combination(ll n, ll r)
{
    //cCr = n! / (r!(n-r)!) = nPr / r!
    map<int, int> molecule;
    map<int, int> denomimator;
    rep1(i, n + 1)
    {
        auto tmp = decompositPrime(i);
        for (auto tm : tmp)
            molecule[tm.first] += tm.second;
    }
    rep1(i, r + 1)
    {
        auto tmp = decompositPrime(i);
        for (auto tm : tmp)
            denomimator[tm.first] += tm.second;
    }
    rep1(i, n - r + 1)
    {
        auto tmp = decompositPrime(i);
        for (auto tm : tmp)
            denomimator[tm.first] += tm.second;
    }
    for (auto deno : denomimator)
        molecule[deno.first] -= deno.second;
    ll res = 1;
    for (auto mole : molecule)
    {
        if (mole.first == 1 || mole.second == 0)
            continue;
        res *= mole.first * mole.second;
    }
    return res;
}

signed main()
{
    gearup;
    int n;
    cin >> n;
    auto res = combination(n, n / 2);
}
