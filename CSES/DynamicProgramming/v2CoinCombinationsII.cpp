#include <bits/stdc++.h>

using namespace std;

const int MOD = (long long)1e9 + 7ll;

void solve(){
  int n, x;
  cin >> n >> x;

  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  vector<int> dp(x+1);
  dp[0] = 1;


  for(int i=0; i<n; i++){ // moedas
    for(int j=1; j<=x; j++){ // valor
      if(j-v[i]>=0){
        dp[j] = (dp[j] + dp[j-v[i]]) % MOD;
      }
    }
  }

  cout << dp[x] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
}
