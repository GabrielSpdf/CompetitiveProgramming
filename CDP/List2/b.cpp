#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI(0, (v).size()) cerr << (v)[i] << " "; cerr << "\n";
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI(0, (v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI(0, (v).size()) { FORJ(0, (v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 
#define rall(v) (v).rbegin(), (v).rend() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  
  vi v;
  FORI(0, (int)s.size()) if(s[i]=='1') v.pb(i);
  
  int winner=LLONG_MAX;
  int dist=LLONG_MAX;
  if(v.size()>0){
    winner = min(v[0], n-v[0]-1);
    if(v.size()>1) winner = min(winner, min(v[(int)v.size()-1], n-v[(int)v.size()-1]-1));
  }
  int ans=n;
  if(winner!=LLONG_MAX){
    ans=2*(n-winner);
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
