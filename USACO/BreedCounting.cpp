#include <bits/stdc++.h>

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

struct cows{
	int id1, id2, id3;
};

void solve(){
	int n, q;
	cin >> n >> q;
	vi v(n);
	FORI(0, n) cin >> v[i];

	vector<cows> cows(n+1);
	cows[0].id1 = 0; cows[0].id2 = 0; cows[0].id3 = 0;
	FORI(1, n+1){
		cows[i].id1 = cows[i-1].id1;
		cows[i].id2 = cows[i-1].id2;
		cows[i].id3 = cows[i-1].id3;

		if(v[i-1]==1) cows[i].id1++;
		if(v[i-1]==2) cows[i].id2++;
		if(v[i-1]==3) cows[i].id3++;
	}

	FORI(0, q){
		ii query;
		cin >> query.first >> query.second;

		cout << cows[query.second].id1-cows[query.first-1].id1 << " ";
		cout << cows[query.second].id2-cows[query.first-1].id2 << " ";
		cout << cows[query.second].id3-cows[query.first-1].id3 << "\n";
	}
}

signed main(){
	setIO("bcount");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
