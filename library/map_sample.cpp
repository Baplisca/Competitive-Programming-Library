#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
   int n;
   cin >> n;
   map<string,bool> mp;
   for(int i=0;i<n;i++){
       string s;
       cin >> s;
       if(mp[s]==false)mp[s] = true;
       else mp[s] = false;
   }
   int count = 0;
   for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
       if(itr->second)count++;
   }
   cout << count << endl;
}
