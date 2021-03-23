#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());
 
vector<int> color;
bool dfs(vvl &g,int v,int now = 0){
    color[v] = now;
    for (auto next_v : g[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == now) return false; // 同じ色が隣接したらダメ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(g, next_v , 1 - now)) return false;
    }
    return true;
}
//参考 https://qiita.com/drken/items/a803d4fc4a727e02f7ba#%E9%A1%9E%E9%A1%8C
signed main()
{   
    gearup;
    int n,m; cin >> n >> m;
    vvl g(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--;b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    color.resize(n,-1);
    bool is_bipartite = true;
    for (int v = 0; v < n; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        if (!dfs(g, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}