#include <bits/stdc++.h>
#include <vector>

#define int long long

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &a: v) cin >> a;
  sort(v.begin(), v.end());

  string ans="YES";
  for(int i=1; i<n-1; i+=2){
    if(v[i]!=v[i+1])
      ans="NO";
  }
  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
