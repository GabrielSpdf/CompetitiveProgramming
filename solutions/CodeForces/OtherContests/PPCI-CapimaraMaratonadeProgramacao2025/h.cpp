#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i].first >> v[i].second;
  }

  vector<vector<int>> dp(m+1, vector<int>(2, 0));
  for(int i=0; i<n; i++){
    int custo = v[i].first;
    int poder = v[i].second;
    for(int j=m; j>=0; j--){
      dp[j][1] = max(dp[j][1], dp[j][0]+poder); // vou usar sobrecarga

      if(j>=custo){ // se eu consigo colocar mais alguma coisa
        dp[j][0] = max(dp[j-custo][0]+poder, dp[j][0]); // nao usar sobrecarga
        dp[j][1] = max(dp[j-custo][1]+poder, dp[j][1]); // ja usei sobrecarga
      }
    }
  }
  cout << max(dp[m][0], dp[m][1]) << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
