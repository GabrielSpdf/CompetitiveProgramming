#include <algorithm>
#include <bits/stdc++.h>

#define int long long

using namespace std;

void fill_str(int l, int r, string& s, vector<int>& v){
  int mn = min(v[l], v[r]);
  int mx = max(v[l], v[r]);
  for(int i=l; i<r; i++){
    if(v[i]>mn && v[i]<mx)
      s[i]='1';
  }
}

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &a: v) cin >> a;
  string s;
  cin >> s;

  int mn = *min_element(v.begin(), v.end());
  int mx = *max_element(v.begin(), v.end());
  set<int> movs = {0, n-1};

  for(int i=0; i<n; i++){
    if(v[i]==mn) movs.insert(i);
    if(v[i]==mx) movs.insert(i);
  }

  vector<pair<int, int>> cands;
  for(int l : movs){
    for(int r : movs){
      if(l<r){
        cands.push_back({l, r});
      }
    }
  }
  int max_try=(1<<cands.size());

  for(int i=0; i<max_try; i++){
    vector<pair<int, int>> curr_movs;
    int qtd=0;
    for(int j=0; j<cands.size(); j++){
      if((i>>j) & 1){
        curr_movs.push_back(cands[j]);
        qtd++;
      }
    }
    if(qtd>5)
      continue;

    string aux(n, '0');
    for(int i=0; i<(int)curr_movs.size(); i++){
      fill_str(curr_movs[i].first, curr_movs[i].second, aux, v);
    }

    bool has_ans=true;;
    for(int i=0; i<n; i++){
      if(s[i]=='1' && aux[i]=='0'){
        has_ans=false;
        break;
      }
    }

    if(has_ans){
      cout << curr_movs.size() << "\n";
      for(int i=0; i<(int)curr_movs.size(); i++){
        cout << curr_movs[i].first+1 << " " << curr_movs[i].second+1 << "\n";
      }
      return;
    }
  }
  cout << "-1\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t; while(t--)
    solve();

  return 0;
}
