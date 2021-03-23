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
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

//問題例 ABC157 E https://atcoder.jp/contests/abc157/tasks/abc157_e
signed main()
{   
    gearup;
    int n,q;string s;
    cin >> n >> s >> q;
    vector<BIT<int> > bit(26,BIT<int>(n+10));
    rep(j,n)bit[s[j]-'a'].add(j+1,1);

    rep(i,q){
        int type; cin >> type;
        if(type == 1){
            int idx;char c;
            cin >> idx >> c; idx--;
            char pc = s[idx];
            s[idx] = c;
            bit[pc - 'a'].add(idx+1,-1);
            bit[c - 'a'].add(idx+1,1);
        }
        else{
            int l,r; cin >> l >> r;
            ll res = 0;
            rep(j,26) if(bit[j].sum(l,r+1))res++;
            out(res);
        }
    }
    
}
