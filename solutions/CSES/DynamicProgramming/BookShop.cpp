#include <bits/stdc++.h>

// #define int long long

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
  int n, x;
  cin >> n >> x;

  vii books(n);
  for(int i=0; i<n; i++){
    cin >> books[i].first;
  }
  for(int i=0; i<n; i++){
    cin >> books[i].second;
  }

  vector<vi> dp(n, vi(x+1, 0));

  for(int i=books[0].first; i<=x; i++){
    dp[0][i] = books[0].second;
  }

  // .first = preco
  // .second = qtd de paginas
  for(int i=1; i<n; i++){ // qtd
    for(int j=0; j<=x; j++){ // valor
      if(j-books[i].first >= 0){
        dp[i][j] = max(dp[i][j], dp[i-1][j-books[i].first]+books[i].second);
      }

      if(i>0){
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
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
