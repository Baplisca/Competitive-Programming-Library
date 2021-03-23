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

//問題144 E問題 https://atcoder.jp/contests/abc144/tasks/abc144_e
//参考URL https://qiita.com/hamko/items/794a92c456164dcc04ad
signed main()
{   
    gearup;
    ll n,k; cin >> n >> k;
    vl a(n),f(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>f[i];
    sort(rall(a));
    sort(all(f));

    ll ma = 1e12 + 1,mi = -1; //maは右端+1, miは左端-1
    while(ma - mi > 1){
        ll mid = (ma + mi) /2;
        //midの値以下にできるか
        ll ttl = 0;
        rep(i,n){
            ll cnt = mid/f[i]; //切り捨て
            if(cnt < a[i])ttl += a[i] - cnt;
        }
        if(ttl <= k)ma = mid;
        else mi = mid;
    }
    out(ma);
}
