#include<bits/stdc++.h>
using namespace std;

//エラトステネスのふるい O(NloglogN)
vector<int> Eratosthenes(int N){
    vector<bool> is_prime(N+1, true); //最初は全部素数仮定

    vector<int> res;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) { // 素数 i を発見したら
            for (int j = i * 2; j <= N; j += i) {
                is_prime[j] = false; // i の倍数をふるい落とす
            }
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    int n; cin >> n;

    // 結果出力
    for(auto ans:Eratosthenes(n)){
        cout << ans << endl;
    }
}