#include <bits/stdc++.h>
#include <ios>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void solve(){
  int n;
  cin >> n;

  int ans=0;

  for(int i=0; i<=(n/4); i++){
    for(int j=0; j<=(n/2); j++){
      if(n-(4*i)-(2*j)==0){
        ans++;
      }
    }
  }

  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
