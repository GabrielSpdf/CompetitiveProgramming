#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve(){
  int n;
  cin >> n;

  // usar vetor pra alocar recomputacoes
  vector<int> dp(n+1, INF);
  dp[0] = 0;

  for(int i=1; i<=n; i++){
    int temp = i;
    while(temp>0){
      if(temp%10){
        dp[i] = min(dp[i-(temp%10)]+1, dp[i]);
      }
      temp/=10;
    }
  }

  cout << dp[n] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
}
