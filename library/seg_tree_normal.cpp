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

template<typename X> struct SegTree{
    using FX = function<X(X,X)>; // X•X -> X となる関数の型
    int N = 1;       // 葉の数
    FX fx;
    const X EX;
    vector<X> value; // ノードの値を持つ配列
    SegTree(vector<X> v, FX fx_, X EX_):fx(fx_), EX(EX_){
        int size = v.size();
        while (N < size) N *= 2;
        value = vector<X>(2 * N - 1, EX); //完全2分木のノードの個数は2n-1 余計なところをEXで初期化

        //セグ木を最下段から構成
        rep(i,size) value[i+N-1] = v[i];
        for(int i=N-2;i>=0;i--)value[i] = fx(value[2*i+1], value[2*i+2]);
    }
    
    // i (0-indexed) 番目の葉の値に x を適用する
    void update(int i, X x) {
        i += N - 1; // i番目は、配列上では N-1+i 番目 (0-indexed)
        value[i] = x;
        while (i > 0) {
            i = (i - 1) / 2; // ノード i の親ノードの番号に変える
            value[i] = fx(value[i * 2 + 1], value[i * 2 + 2]); // ボトムアップに計算
        }
    }
    //根 (k=0)から l=0, r = Nとして探索
    X query(int a, int b) { return query_solve(a, b, 0, 0, N); }
    // [l,r):value[k]が表している区間 
    X query_solve(int a, int b, int k, int l, int r) {
        // [a, b) の区間に対するクエリについて
        // ノード k （区間 [l, r) 担当）が答える
        if (r <= a || b <= l) return EX; // 区間が被らない場合は 答えに影響しない値(EX) を返す
        if (a <= l && r <= b)
            return value[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
        else {
            X c1 = query_solve(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
            X c2 = query_solve(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
            return fx(c1, c2); // 左右の子の値の fx を取る
        }
    }
};

// セグ木 設計例　
// https://tsutaj.hatenablog.com/entry/2017/03/29/204841
// https://algo-logic.info/segment-tree/#toc_id_3
// 問題例 ABC125 C　GCD BLACKBOARD https://atcoder.jp/contests/abc125/tasks/abc125_c
signed main()
{   
    gearup;
    int n; cin >> n;
    vi v(n);
    rep(i,n)cin >> v[i];
    auto fx = [](int x1, int x2) -> int { return __gcd(x1, x2); };
    int ex = 0;
    SegTree<int> st(v, fx, ex);
    int res = 0;
    rep(i,n){
        int num = __gcd(st.query(0,i), st.query(i+1,n)); //iを除いたgcd
        res = max(res,num);
    }
    out(res);
    return 0;
}