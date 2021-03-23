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

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
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

//問題ABC 165 F https://atcoder.jp/contests/abc165/tasks/abc165_f
signed main()
{   
    int n;cin >> n;
    vl a(n),dp(n,INF),ans(n);
    vvl g(n);
    rep(i,n)cin>>a[i];

    rep(i,n-1){
        int u,v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function<void(int,int)> dfs = [&](int node, int pre_node){
        ans[node] = lower_bound(all(dp), INF) - dp.begin();
        for(int nv:g[node]){
            if(nv == pre_node)continue;
            //LIS
            auto itr = lower_bound(all(dp), a[nv]);
            int pre_num = *itr;
            *itr = a[nv];
            dfs(nv, node);
            *itr = pre_num;
        }
    };
    dp[0] = a[0];
    dfs(0, -1);
    
    rep(i,n)out(ans[i]);

    return 0;
}