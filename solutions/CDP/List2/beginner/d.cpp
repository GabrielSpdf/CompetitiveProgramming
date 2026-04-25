#include <algorithm>
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

int run(vector<string>& grid, vi seq, ii start, int n, int m){
  ii pos = start;
  FORI(0, (int)seq.size()){
    int addx=0, addy=0;
    if(seq[i]==0){ addx++; }
    if(seq[i]==1){ addx--; }
    if(seq[i]==2){ addy++; }
    if(seq[i]==3){ addy--; }

    pos.first+=addx;
    pos.second+=addy;

    if(pos.first<0 || pos.first>n-1 || pos.second<0 || pos.second>m-1 || grid[pos.first][pos.second]=='#') return 0;
    if(grid[pos.first][pos.second]=='E') return 1;
  }
  return 0;
}

void solve(){
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  FORI(0, n){
    cin >> grid[i];
  }
  string s;
  cin >> s;
  vi seq;
  FORI(0, (int)s.size()) seq.pb(s[i]-0x30);

  ii start, end;
  FORI(0, n){
    FORJ(0, m){
      if(grid[i][j]=='S') start=make_pair(i, j);
      if(grid[i][j]=='E') end=make_pair(i, j);
    }
  }
  
  int mov[] = {0, 1, 2, 3};
  vi backup_seq = seq;
  
  int ans=0;
  do{
    seq = backup_seq;
    FORI(0, seq.size()){
      if(seq[i]==0) seq[i]=mov[0];
      else if(seq[i]==1) seq[i]=mov[1];
      else if(seq[i]==2) seq[i]=mov[2];
      else if(seq[i]==3) seq[i]=mov[3];
    }
    ans+=run(grid, seq, start, n, m);
  
  } while(next_permutation(mov, mov+4));

  cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
