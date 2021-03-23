#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
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

signed main()
{   
    gearup;
    string s; cin >> s;
    vector<int> ans(s.size(),0);

    rep(i,s.size()){
        if(s[i]=='R'){
            int idx=1;
            int ct[2]={};
            ct[idx%2]++;
            while(i+1<s.size() and s[i]==s[i+1]){
                idx++;
                ct[idx%2]++;
                i++;
            }
            if(idx%2==1){ //Rが連続しているのが偶数個なら
                ans[i+1]+=ct[0];
                ans[i]+=ct[1];
            }else {
                ans[i+1]+=ct[1];
                ans[i]+=ct[0];
            }
        }
    }

    reverse(all(s));
    reverse(all(ans));

    rep(i,s.size()){
        if(s[i]=='L'){
            int idx=1;
            int ct[2]={};
            ct[idx%2]++;
            while(i+1<s.size() and s[i]==s[i+1]){
                idx++;
                ct[idx%2]++;
                i++;
            }
            if(idx%2==1){
                ans[i+1]+=ct[0];
                ans[i]+=ct[1];
            }else {
                ans[i+1]+=ct[1];
                ans[i]+=ct[0];
            }
        }
    }
    reverse(all(ans));
    rep(i,s.size()){
        if(i)cout <<" ";
        cout << ans[i];
    }
    cout << endl;
}