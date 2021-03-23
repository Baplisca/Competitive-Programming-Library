#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int lcm(int x,int y){
  return x / __gcd(x,y) * y;
}

int main() {
    int n; cin >> n;
    int ans = 1;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        ans = lcm(ans,num);
    }
    cout << ans << endl;
}   

