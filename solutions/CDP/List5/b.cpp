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
	int n, k;
	cin >> n >> k;

	if((n*(n-1))/2 < n*k){ cout << -1 << "\n"; return; }

	vector<map<int, bool>> graph(n);

	FORI(0, n){
		FORJ(0, n){
			if(i==j) continue;
			graph[i][j] = true;
		}
	}
	
	vii ans;
	FORI(0, n){
		int matches=0;
		FORJ(0, n){
			if(matches==k) break;
			if(i==j) continue;
			if(graph[i][j]){ // true
				ans.emplace_back(i+1, j+1); // indexed 1
				graph[i][j]=false;
				graph[j][i]=false;
				matches++;
			}
		}
	}

	cout << n*k << "\n";
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
