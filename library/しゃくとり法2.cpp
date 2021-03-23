#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    set<int> s;
    int right = 0;
    rep(left,n){
        while(right <n && s.count(a[right]) == 0){
            s.insert(a[right]);
            right++;
        }
        if(left == right) right++;
        else s.erase(a[left]);
        res = max(res,1LL*right - left);
    }    
    cout << res << endl;
}
