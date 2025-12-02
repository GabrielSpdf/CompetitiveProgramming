#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  vector<long long> pfs(n+1, 0);
  for(int i=1; i<=n; i++){
    pfs[i] = pfs[i-1]+v[i-1];
  }
  sort(v.begin(), v.end());

  vector<long long> pfs_sorted(n+1, 0);
  for(int i=1; i<=n; i++){
    pfs_sorted[i] = pfs_sorted[i-1]+v[i-1];
  }

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    int type, l, r;
    cin >> type >> l >> r;

    if(type==1){
      cout << pfs[r]-pfs[l-1] << "\n";
    }
    else{
      cout << pfs_sorted[r]-pfs_sorted[l-1] << "\n";
    }
  }

  return 0;
}
