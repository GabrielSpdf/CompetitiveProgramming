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
	vi v(n);
	for(auto &a: v ) cin >> a ;
	
	vii ans;
	FORI(0, n){
		int mini = v[i];
		int idx=i;

		FORJ(i+1, n){
			if(v[j]<mini){
				idx=j;
				mini = v[j];
			}
		}

		ans.emplace_back(idx, i);
		swap(v[i], v[idx]);
	}

	cout << ans.size() << "\n";
	FORI(0, (int)ans.size()){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
