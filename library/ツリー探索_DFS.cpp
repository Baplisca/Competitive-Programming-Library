#include <bits/stdc++.h>
using namespace std;

#define int long long
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

//問題ABC126 D https://atcoder.jp/contests/abc126/tasks/abc126_d
//参考　https://drken1215.hatenablog.com/entry/2019/05/19/224500
//ツリー探索の例
signed main()
{   
    gearup;
    int n; cin >> n;
    vector<vector<pair<int,int> > > g(n);
    rep(i,n-1){
        int u,v,w; cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vl dists(n,L_INF);
    function<void(int,int,int) > dfs = [&](int node,int pre_node,int col){
        dists[node] = col;
        for(auto nv:g[node]){
            if(nv.first == pre_node)continue; //逆流防止
            if(nv.second & 1) dfs(nv.first, node, 1-col);
            else dfs(nv.first, node, col);
        }
    };
    dfs(0, -1 ,1);
    rep(i,n){
        out(dists[i]);
    }
}