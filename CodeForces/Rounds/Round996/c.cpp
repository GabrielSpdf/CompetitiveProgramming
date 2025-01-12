#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void pgrid(vvll grid, int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	/* cout << "\n"; */
}

void calc(vvll& grid, vector<vector<bool>>& bool_grid, int ipos, int jpos, int n, int m){
	// coluna
	ll sumcol=0, cntcol=0;
	for(int i=0; i<n; i++){
		if(bool_grid[i][jpos]==true) cntcol++;
		sumcol+=grid[i][jpos];
	}

	if(cntcol==1){
		grid[ipos][jpos]=(0-sumcol);
	}
	else{
		ll sumlin=0, cntlin=0;
		for(int j=0; j<m; j++){
			if(bool_grid[ipos][j]==true) cntlin++;
			sumlin+=grid[ipos][j];
		}

		grid[ipos][jpos]=(0-sumlin);
	}

	bool_grid[ipos][jpos]=false;
}


void solve(){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vvll grid(n, vll(m));
	vector<vector<bool>> bool_grid(n, vector<bool>(m));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> grid[i][j];
			bool_grid[i][j]=false;
		}
	}

	int i=0, j=0;
	bool_grid[i][j]=true;

	vpll path; //vector<pair<ll, ll>>
	path.emplace_back(make_pair(0, 0));

	for(int k=0; k<(int)s.size(); k++){
		if(s[k]=='D') i++;
		if(s[k]=='R') j++;
		path.emplace_back(make_pair(i, j));
		bool_grid[i][j]=true;
	}
	
	for(auto nxt: path){
		calc(grid, bool_grid, nxt.first, nxt.second, n, m);
	}

	pgrid(grid, n, m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
