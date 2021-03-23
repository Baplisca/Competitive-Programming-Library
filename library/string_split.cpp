#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

vector<string> split(string str, string separator) {
    if (separator == "") return {str};
    vector<string> result;
    string tstr = str + separator;
    long l = tstr.length(), sl = separator.length();
    string::size_type pos = 0, prev = 0;
    
    for (;pos < l && (pos = tstr.find(separator, pos)) != string::npos; prev = (pos += sl)) {
        result.emplace_back(tstr, prev, pos - prev);
    }
    return result;
}

int main() {
   string s; cin >> s;
   vector<string> sub_s = split(s,"+");
   int count = 0;
   for(int i=0;i<sub_s.size();i++){
       if(sub_s[i].find("0") == -1) count++;
   }
   cout << count << endl;
}   

