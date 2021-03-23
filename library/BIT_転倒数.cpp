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

// クエリあたりO(lonN)で処理できる
// 1-indexedなので注意
struct BIT {
    private:
    vector<int> bit;
    int N;

    public:
    BIT(int size) {
      N = size;
      bit.resize(N + 1);
    }

    // aがインデックスの場所,wはaの値
    void add(int a, int w) {
      for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }

    // 1~Nまでの和を求める
    int sum(int a) {
      int ret = 0;
      for (int x = a; x > 0; x -= x & -x) ret += bit[x];
      return ret;
    }
};

//問題例 転倒数　https://atcoder.jp/contests/chokudai_s001/tasks/chokudai_S001_j
signed main()
{   
    gearup;
    int n; cin >> n;
    BIT bit(n);
    ll res = 0;
    rep(i,n){
        int a;cin>>a;
        res += i - bit.sum(a);
        bit.add(a,1);
    }
    out(res);
}