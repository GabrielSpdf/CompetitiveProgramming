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

  vi dp(x+1, 0);

  for(int i=0; i<n; i++){
    for(int j=x; j>=0; j--){
      if(j-books[i].first >= 0){
        dp[j] = max(dp[j], dp[j-books[i].first]+books[i].second);
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
