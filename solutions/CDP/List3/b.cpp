#include <bits/stdc++.h>
#include <numeric>

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

int fck_case(vii& points, vi& v, int val){
  int return_sum=0;
  int sum=0;
  int piece=0;
  
  auto it = v.begin();
  for(auto [a, b]: points){
    piece=0;
    FORI(a, b){
      piece+=v[i];
    }

    FORI(a, b){
      if(piece-v[i]>=val){ sum+=v[i]; piece-=v[i]; }
    }
  }
  
  return_sum = max(return_sum, sum);
  sum=0;
  for(auto [a, b]: points){
    piece=0;
    FORI(a, b){
      piece+=v[i];
    }

    for(int i=b-1; i>=a; i--){
      if(piece-v[i]>=val){ sum+=v[i]; piece-=v[i]; }
    }
  }
  return_sum = max(return_sum, sum);

  return return_sum;
}

void solve(){
  int n, m, val;
  cin >> n >> m >> val;
  vi v(n);
  for(auto &a: v) cin >> a;
  
  vi pieces;
  vii points;
  int sum=0, count=0;
  int first=0;
  FORI(0, n){
    sum+=v[i];
    if(sum>=val && count<m){
      pieces.pb(sum);
      sum=0;
      count++;
      points.emplace_back(first, i+1);
      first=i+1;
    }
    if(i==n-1 && sum!=0){ pieces.pb(sum); points.emplace_back(first, n); }
  }
  sort(all(pieces));
  
  int ans=LLONG_MIN;
  if(count<m || pieces[0]<val){ ans=-1;  }
  else if(count==m){ cerr << "oras\n"; ans=fck_case(points, v, val); } //!!!!!!!!!!
  else{
    FORI(0, (int)pieces.size()){
      if(pieces[i]<val || i>m-1){ ans=pieces[i]; break; }
    }
  }

  pieces.clear();
  points.clear();
  sum=0; count=0;
  first=0;
  for(int i=n-1; i>=0; i--){
    sum+=v[i];
    if(sum>=val && count<m+1){
      pieces.pb(sum);
      sum=0;
      count++;
      points.emplace_back(first, i+1);
      first=i+1;
    }
    if(i==0 && sum!=0){ pieces.pb(sum); count++; points.emplace_back(first, n); }
  }
  sort(all(pieces));
  tvi(pieces);
  cerr << "pre_ans: " << ans << "\n";

  if(count<m || pieces[0]<val){ ans=max(ans, -1LL); }
  else if(count==m){ ans=max(ans, fck_case(points, v, val)); } //!!!!!!!!!!
  else{
    sort(all(pieces));
    FORI(0, (int)pieces.size()){
      if(pieces[i]<val || i>m-1){ ans=max(ans, pieces[i]); break; }
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
