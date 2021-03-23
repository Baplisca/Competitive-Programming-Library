#include<bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};
vector<bool> dp(100010,false);

int main() {
    string S;
    cin >> S;

    dp[0] = 1;
    for(int i = 0; i < S.size(); ++i){
        if(!dp[i])continue; // そこまでで矛盾があったらとりあえず無視
        for(string s : divide){
            if(S.substr(i, s.size()) == s){ // うまく切れたら先に進む
                dp[i + s.size()] = 1;
            }
        }
    }
    cout << (dp[S.size()] ? "YES" : "NO") << endl;
    return 0;
}