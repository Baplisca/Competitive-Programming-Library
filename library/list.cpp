#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long INF = 1LL << 60;
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}

signed main()
{   
    gearup;
    list<int> L;
    ll n; cin >> n;
    string s;
    int a;
    rep(i,n){
        cin >> s;
        if(s == "insert"){
            cin >> a;
            L.push_front(a);
        }else if(s == "delete"){
            cin >> a;
            for(list<int>::iterator it = L.begin();it!=L.end();it++){
                if(*it == a){
                L.erase(it);
                break;
                }
            }
        }else if(s == "deleteFirst"){
            L.pop_front();
        }else if(s == "deleteLast"){
            L.pop_back();
        }
    }
    for(list<int>::iterator it=L.begin();it!=L.end();it++){
        if(it!=L.begin())cout <<" ";
        cout << *it;
    }
    cout << endl;
}
