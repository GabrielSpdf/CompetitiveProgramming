#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
  int n;
  cin >> n;
  int y, r;
  cin >> y >> r;

  cout << min(n, y/2 + r) << "\n";
}

signed main(){
  int t; cin >> t; while(t--)
    solve();
  return 0;
}
