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

template<class T> struct RSQ{
    int N = 1;       // 葉の数
    vector<T> value; // ノードの値を持つ配列
    RSQ(vector<T> v){
        int size = v.size();
        while (N < size) N *= 2;
        value = vector<T>(2 * N - 1, 0); //完全2分木のノードの個数は2n-1 余計なところを0で初期化

        //セグ木を最下段から構成
        rep(i,size) value[i+N-1] = v[i];
        for(int i=N-2;i>=0;i--)value[i] = value[2*i+1] + value[2*i+2];
    }
    
    // i (0-indexed) 番目の葉の値に x を加える
    void add(int i, T x) {
        i += N - 1; // i番目は、配列上では N-1+i 番目 (0-indexed)
        value[i] += x;
        while (i > 0) {
            i = (i - 1) / 2; // ノード i の親ノードの番号に変える
            value[i] = value[i * 2 + 1] + value[i * 2 + 2]; // ボトムアップに計算
        }
    }
    //根 (k=0)から l=0, r = Nとして探索
    T query(int a, int b) { return query_solve(a, b, 0, 0, N); }
    // [l,r):value[k]が表している区間 
    T query_solve(int a, int b, int k, int l, int r) {
        // [a, b) の区間に対するクエリについて
        // ノード k （区間 [l, r) 担当）が答える
        if (r <= a || b <= l) return 0; // 区間が被らない場合は 答えに影響しない値(INF) を返す
        if (a <= l && r <= b)
            return value[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
        else {
            T c1 = query_solve(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
            T c2 = query_solve(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
            return (c1 + c2); // 左右の子の値の 合計 を取る
        }
    }
};

// セグ木 設計例　
// https://tsutaj.hatenablog.com/entry/2017/03/29/204841
// 問題例 AOJ　RSQ https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
signed main()
{   
    gearup;
    int n, q;
    cin >> n >> q;
    vl v(n,0);
    RSQ<ll> rsq(v);
    int m,x,y;
    rep(j,q){
        cin >> m >> x >> y;
        if(m == 1){ //find
             int p = rsq.query(x-1,y); //半開区間 [x-1,y)
             cout << p << endl;
        }
        else rsq.add(x-1,y); //update
    }
    return 0;
}