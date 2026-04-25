#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
  int n; cin >> n;
  vector<int> v(2*n);
  map<int, int> freq;
  for(int i=0; i<2*n; i++){
    cin >> v[i];
    freq[v[i]]++;
  }

  int ans=0;
  int odds=0, dep=0;
  for(auto [k, v] : freq){
    if(v&1) odds++;
    else if(v%4==0) dep++;

    if(v&1) ans++;
    else ans+=2;
  }

  if((dep&1) && odds==0) ans-=2;

  cout << ans << "\n";
}

signed main(){
  int t; cin >> t; while(t--)
    solve();
  return 0;
}
