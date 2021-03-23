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
typedef long double ld;
typedef long long int ll;
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

//辺彩色の例
//問題 ABC146 D https://atcoder.jp/contests/abc146/tasks/abc146_d
signed main(){
    gearup;
    ll n;cin>>n;
    vvl G(n);
    vpii E_in;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        E_in.push_back(make_pair(a,b));
    }

    queue<int> que;
    vb used(n, false); //そのノードについて調べたか
    vl parent(n);
    int max_color = 0;
    map<pair<int, int>, int> E_num; // 辺への割り振った番号を保持する
    que.emplace(0);
    used[0] = true;
    while(!que.empty()){
        int node = que.front();
        que.pop();
        int num_color = 0;
        for(auto nv:G[node]){
            if(used[nv])continue;
            num_color++;
            used[nv] = true;
            if(num_color == parent[node])num_color++;
            pair<int, int> p = make_pair(node, nv);
            E_num[p] = num_color; //辺彩色
            parent[nv] = num_color;
            que.push(nv); //次の状態をqueueへ格納
        }
        chmax(max_color,num_color);
    }
    out(max_color);
    for(auto i:E_in){
        out(E_num[i]);
    }
}