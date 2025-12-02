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

  int difs = 0;
  int lst_dif = -1;
  for(int i=0; i<n; i++){
    if(a[i] != b[i]){
      difs++;
      lst_dif = i+1;
    }
  }
  if(difs%2 == 0) {
    cout << "Tie\n";
    return;
  }
  if(lst_dif%2 != 0) {
    cout << "Ajisai\n";
  } else {
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
