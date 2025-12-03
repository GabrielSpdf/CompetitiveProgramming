#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> grid[i][j];
    }
  }

  vector<int> dp(n, 0);
  if(grid[0][0] != '*'){
    dp[0] = 1;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(grid[i][j]=='*'){
        dp[j] = 0;
        continue;
      }

      if(j>0){
        dp[j] = (dp[j] + dp[j-1]) % MOD;
      }
    }
  }

  cout << dp[n-1] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
