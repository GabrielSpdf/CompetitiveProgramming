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

  vector<vector<int>> dp(n, vector<int>(x+1, 0));

  // preciso apenas olhar para x
  // nao posso repetir combinacoes
  // transicoes:
  // somar moeda atual e continuar com ela |
  // ir para proxima moeda
  for(int i=0; i<n; i++){
    dp[i][0] = 1;
  }

  for(int i=0; i<n; i++){
    for(int j=1; j<=x; j++){
      if(j-v[i]>=0){
        dp[i][j] = (dp[i][j] + dp[i][j-v[i]]) % MOD;
      }
      if(i-1>=0){
        dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      }
    }
  }

  cout << dp[n-1][x] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
}
