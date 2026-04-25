#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void solve(){
  int n;
  cin >> n;
  vi a(n), b(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<n; i++){
    cin >> b[i];
  }

  int ans=0, last_idx=-1;
  for(int i=0; i<n; i++){
    ans = a[i] ^ b[i] ^ ans;
    if(a[i] ^ b[i])
      last_idx=i;
  }

  int bit;
  for(int i=0; i<20; i++){
    if(ans&1<<i){
      bit = i;
    }
  }
  for(int i=0; i<n; i++){
    if((a[i]^b[i])&1<<bit){
      last_idx = i;
    }
  }

  if(ans==0){
    cout << "Tie\n";
    return;
  }

  if(last_idx%2==0){
    cout << "Ajisai\n";
  }
  else{
    cout << "Mai\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
