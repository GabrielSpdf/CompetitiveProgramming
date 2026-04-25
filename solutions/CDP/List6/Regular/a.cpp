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
	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	
	vii v(n);
	FORI(0, n){
		cin >> v[i].first >> v[i].second;
	}

	FORI(0, n){
		v[i].first = max((v[i].first*t1*((100-k)))+100*v[i].second*t2, (v[i].second*t1*((100-k)))+100*v[i].first*t2);
		v[i].second = i+1;
	}

	sort(all(v), [] (auto x, auto y) {
		if(x.first != y.first) {
			return x.first > y.first;
		}
		return x.second < y.second;
	});

	FORI(0, n){
		cout << fixed << setprecision(2) << v[i].second << " " << double(v[i].first)/100  << "\n";
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
