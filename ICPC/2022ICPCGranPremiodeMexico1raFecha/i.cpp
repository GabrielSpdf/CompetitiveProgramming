#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    string s;
    s = to_string(n);

    int ans = 0;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == '0') continue;
        if((n%(s[i] - '0'))==0) ans++;
    }
    cout << ans << "\n";
}

signed main(){
    solve();

    return 0;
}