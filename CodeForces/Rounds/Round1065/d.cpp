#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void solve(){
  int n;
  cin >> n;
  vi v(n);
  for(auto &a: v) cin >> a;

  vi pf_min(n), sf_max(n);
  pf_min[0] = v[0];
  sf_max[n-1] = v[n-1];
  for(int i=1; i<n; i++){
    pf_min[i] = min(pf_min[i-1], v[i]);
  }
  for(int i=n-2; i>=0; i--){
    sf_max[i] = max(sf_max[i+1], v[i]);
  }

  for(int i=0; i<n-1; i++){
    if(pf_min[i] > sf_max[i+1]){
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
