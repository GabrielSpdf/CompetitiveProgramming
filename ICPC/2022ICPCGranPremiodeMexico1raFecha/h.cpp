#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    int x = n/4;
    int y = x;
    while (2*x + 2*y <= n) {
        y++;
    }
    y--;
    cout << x*y << "\n";
}

signed main(){
    solve();

    return 0;
}
