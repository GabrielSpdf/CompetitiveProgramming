#include <bits/stdc++.h>
#include <iterator>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI((v).size()) cerr << (v)[i] << " "; cerr << "\n"
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI((v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI((v).size()) { FORJ((v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct plays{
	int P, H, S;
};

void solve(){
	int n;
	cin >> n;
	
	vector<plays> pfs(n+1);
	pfs[0].P = pfs[0].H = pfs[0].S = 0;

	vi vp, vs, vh;
	FORI(1, n+1){
		pfs[i].P = pfs[i-1].P;
		pfs[i].S = pfs[i-1].S;
		pfs[i].H = pfs[i-1].H;
		
		string s;
		cin >> s;
		if(s == "P") pfs[i].P++;
		if(s == "S") pfs[i].S++; 
		if(s == "H") pfs[i].H++; 
	}

	int max_wins=0;
	FORI(0, n+1){
		int bf_win=max(pfs[i].P, max(pfs[i].S, pfs[i].H));
		int af_win=max(pfs[n].P - pfs[i].P, max(pfs[n].S - pfs[i].S, pfs[n].H - pfs[i].H));

		max_wins = max(max_wins, bf_win+af_win);
	}

	cout << max_wins << "\n";
}

signed main(){
	setIO("hps");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
