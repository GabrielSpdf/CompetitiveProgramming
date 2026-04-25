#include <bits/stdc++.h>
#include <ios>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void solve(){
  int n;
  cin >> n;
  vi v(n);

  bool fst=false, lst=false;
  for(int i=0; i<n; i++){
    cin >> v[i];
    if(v[i]==-1){
      if(i==0)
        fst=true;
      else if(i==n-1)
        lst=true;

      v[i]=0;
    }
  }

  int sum=0;
  vi prefix(n, 0);
  for(int i=1; i<n; i++){
    prefix[i] = v[i]-v[i-1];
    sum+=prefix[i];
  }

  if(sum>0){
    if(fst){
      v[0]=min(abs(sum), (int)1e6);
      sum-=v[0];
    }
  }
  else if(sum<0){
    if(lst){
      v[n-1]=min(abs(sum), (int)1e6);
      sum+=v[n-1];
    }
  }

  cout << abs(sum) << "\n";
  for(int i=0; i<n; i++){
    cout << v[i] << " ";
  }
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
