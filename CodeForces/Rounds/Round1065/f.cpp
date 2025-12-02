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

  vi pf_min(n);
  vector<ii> sf_max(n+1);

  pf_min[0] = v[0];
  sf_max[n-1] = {v[n-1], n-1};

  for(int i=1; i<n; i++){
    pf_min[i] = min(pf_min[i-1], v[i]);
  }

  for(int i=n-1; i>=0; i--){
    sf_max[i] = max(sf_max[i+1], {v[i], i});
  }

  for(int i=0; i<n-1; i++){
    if(pf_min[i] > sf_max[i+1].first){
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
  for(int l=0; l<n;){
    int r = sf_max[l].second;
    for(int i=l; i<r; i++){
      cout << v[i] << " " << v[r] << "\n";
    }
    if(l>1){
      cout << pf_min[l-1] << " " << v[r] << "\n";
    }
    l = r+1;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
