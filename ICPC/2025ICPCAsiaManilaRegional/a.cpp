#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    if(n%2!=0) cout << s[n/2] << "\n";  // impar
    else cout << ":)\n";
}

int main(){
    solve();

    return 0;
}