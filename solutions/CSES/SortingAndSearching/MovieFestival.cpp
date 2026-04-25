#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI(0, (v).size()) cerr << (v)[i] << " "; cerr << "\n";
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI(0, (v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI(0, (v).size()) { FORJ(0, (v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }

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

void solve(){
	int n;
	cin >> n;

	vpii vp(n);
	for(auto &[a, b] : vp){
		cin >> a >> b;
	}
	
	sort(vp.begin(), vp.end(), [](const pair<int, int>&a, const pair<int, int>&b){
		return a.second < b.second;
	});
	
	int ans=0, curr=0;
	for(int i=0; i<(int)vp.size(); i++){
		if(vp[i].first < curr){
			continue;
		}
		curr = vp[i].second;
		ans++;
	}
	cout << ans << "\n";     
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
