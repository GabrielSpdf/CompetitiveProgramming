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
  int n;
  cin >> n;
  deque<int> v(n);
  for(auto &a: v) cin >> a;

  int cntz=0;
  FORI(0, v.size()){
    if(v[i]==0) cntz++;
  }

  vii vp;
  int k=0;
  if(cntz==0){ vp.pb(make_pair(1, v.size())); k++; }
  else{
    if(v[0]==0){
      k++;
      vp.pb(make_pair(1,2));
      v.pop_front();
      v[0]=1;
    }
    if(v[v.size()-1]==0){
      k++;
      vp.pb(make_pair(v.size()-1, v.size()));
      v.pop_back();
      v[v.size()-1]=1;
    }
    
    bool alr=false;
    for(int i=1; i<v.size(); i++){
      if(v[i]==0){
        k+=2;
        vp.pb(make_pair(i+1, v.size()));
        vp.pb(make_pair(1, i+1));
        alr=true;
        break;
      }
    }
    if(!alr){ vp.pb(make_pair(1, v.size())); k++; }
  }

  cout << k << "\n";
  FORI(0, vp.size()){
    cout << vp[i].first << " " << vp[i].second << "\n";
  }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
