#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
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
 

//ABC 037 D問題　URL https://abc037.contest.atcoder.jp/tasks/abc037_d
int h,w;   
ll arr[1000][1000];
ll dp[1000][1000];
 
ll bfs(int y, int x){
    if(dp[y][x] > -1) return dp[y][x];
 
    ll comb = 1;
    for(int i=0;i<8;i+=2){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(-1 < nx and nx < w and -1 < ny and ny < h && arr[ny][nx] < arr[y][x]){
            comb += bfs(ny, nx)%MOD;
        }
    }
    return dp[y][x] = comb%MOD;
}
 
signed main(){
    gearup;

    cin >> h >> w;
    rep(i,h)rep(j,w) cin >> arr[i][j];
    
    memset(dp, -1, sizeof(dp));
 
    ll ans = 0;
    rep(i,h)rep(j,w)ans += bfs(i,j)%MOD;

    out(ans%MOD);
}
