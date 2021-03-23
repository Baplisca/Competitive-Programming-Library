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

//区間更新 RUQのRMQ
template <typename T> struct LazySegmentTree{
    int n;
    vector<ll> node, lazy;

    LazySegmentTree(vector<ll> v){
        int size = (int)v.size();
        n = 1;
        while(n < size)n *= 2;
        node.resize(2*n-1,INF);
        lazy.resize(2*n-1,INF);
        rep(i,size)node[i+n-1] = v[i];
        for(int i=n-2;i>=0;i--)node[i] = min(node[i*2+1], node[i*2+2]);
    }
    //k番目(0-indexed)のノードの遅延評価
    void lazy_eval(int k){
        //遅延配列がINFでなければ続ける
        if(lazy[k] != INF){
            //最下段でなければ更新
            if(k < n-1){
                lazy[2*k+1] = lazy[k];
                lazy[2*k+2] = lazy[k];
            }
            node[k] = lazy[k];
            lazy[k] = INF;

        }
    }
    void update(int a, int b, T x, int k, int l, int r) {
        lazy_eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            lazy_eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            node[k] = min(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }
    //半開区間 [a,b)
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
 
    T query_solve(int a, int b, int k, int l, int r) {
        lazy_eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return node[k];
        } else {  // 一部区間が被る時
            T vl = query_solve(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_solve(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    //半開区間 [a,b)
    T query(int a, int b) { return query_solve(a, b, 0, 0, n); }
};

//問題例 AOJ https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
signed main()
{   
    gearup;
    int n,q; cin >> n >> q;
    vl v(n,INF);
    LazySegmentTree<ll> lst(v);
    int que,s,t,x;
    rep(i,q){
        cin >> que;
        if(que == 0){
            cin >> s >> t >> x;
            lst.update(s, t+1, x);
        }
        else{
            cin >> s >> t;
            int num = lst.query(s,t+1);
            out(num);
        }
    }
}
