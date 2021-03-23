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
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> siz;  // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N), siz(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            siz[i] = 1;
        }
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        // merge technique（小を大にくっつける）
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x)
    {
        return siz[root(x)];
    }
};

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
    int a, b, cost;

    // コストの大小で順序定義
    bool operator<(const Edge &o) const
    {
        return cost < o.cost;
    }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
    int n;           // 頂点数
    vector<Edge> es; // 辺集合

    // クラスカル法で無向最小全域木のコストの和を計算する
    // グラフが非連結のときは最小全域森のコストの和となる
    int kruskal()
    {
        // コストが小さい順にソート
        sort(es.begin(), es.end());

        UnionFind uf(n);
        int min_cost = 0;

        rep(ei, es.size())
        {
            Edge &e = es[ei];
            if (!uf.same(e.a, e.b))
            {
                // 辺を追加しても閉路ができないなら、その辺を採用する
                min_cost += e.cost;
                uf.unite(e.a, e.b);
            }
        }

        return min_cost;
    }
};

//最小全域木　クラスカル法
//問題例AOJ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja
signed main()
{
    gearup;
    Graph g;
    int m;
    cin >> g.n >> m;
    rep(i, m)
    {
        Edge e;
        //頂点は、0-indexedなので注意
        cin >> e.a >> e.b >> e.cost;
        g.es.push_back(e);
    }
    out(g.kruskal());
}
