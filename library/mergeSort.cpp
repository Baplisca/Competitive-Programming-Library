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

#define MAX 500000
int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;

void merge(int A[],int n,int left,int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    //L[0...n1], R[0...n2] を生成
    rep(i,n1) L[i] = A[left + i];
    rep(i,n2) R[i] = A[mid+i];
    L[n1] = R[n2] = INF;
    int i = 0;
    int j = 0;
    FOR(k,left,right){
      cnt++;
        if (L[i] <= R[j]){
        A[k] = L[i];
        i = i + 1;
        }
        else{
        A[k] = R[j];
        j = j + 1;
        }
    }
}
void mergeSort(int A[],int n,int left, int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A,n, left, mid);
        mergeSort(A,n, mid, right);
        merge(A,n,left, mid, right);
    }
}
signed main()
{   
    gearup;
    int A[MAX],n;
    cnt = 0;
    cin >> n;
    rep(i,n) cin >> A[i];

    mergeSort(A,n,0,n);

    rep(i,n){
        if(i)cout <<" ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
}