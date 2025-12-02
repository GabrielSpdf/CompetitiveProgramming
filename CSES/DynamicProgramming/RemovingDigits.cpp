#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int sol(vector<int>& dp, int num){
  if(num<0){
    return INF;
  }
  if(dp[num]!=INF){
    return dp[num];
  }

  // string s = to_string(num); // ruim em termos de complexidade
  int temp = num;

  while(temp>0){
    if(temp%10>0){
      dp[num] = min(dp[num], sol(dp, num-(temp%10))+1);
    }

    temp/=10;
  }

  return dp[num];
}

void solve(){
  int n;
  cin >> n;

  // usar vetor pra alocar recomputacoes
  vector<int> dp(n+1, INF);
  dp[0] = 0;

  cout << sol(dp, n) << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
}
