#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
   int n;
   cin >> n;
   for (int bit = 0; bit < (1<<n); ++bit) {
       int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) sum += a[i];
        }
    }
}
