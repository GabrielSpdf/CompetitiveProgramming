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
	for(auto &a: v) cin >> a;
	for(int i=1; i<n; i++){
		if(abs(v[i]-v[i-1])>1){
			cout << "0\n";
			return;
		}
	}

	vector<char> sol1(n), sol2(n);
	sol1[0] = ']';
	sol2[0] = '[';
	
	// if(v[i]-v[i-1]==1) [[
	// if(v[i]-v[i-1]==-1) ]]
	// if(v[i]-v[i-1]==0) [] ou ][
	for(int i=1; i<n; i++){
		int diff = v[i] - v[i-1];
		if(diff == 0){
			sol1[i] = (sol1[i-1] == '[') ? ']' : '[';
			sol2[i] = (sol2[i-1] == '[') ? ']' : '[';
		}
		else{
			sol1[i] = sol1[i-1];
			sol2[i] = sol2[i-1];
		}
	}

	auto check = [&](vector<char> sol, vi v){
		int appr=1;
		int n = (int)v.size();
		for(int i=1; i<n; i++){
			if(sol[i] == ']'){
				appr++;
			}
		}

		if(appr != v[0]){
			return false;
		}

		for(int i=0; i<n-1; i++){
			if(sol[i] == ']' && sol[i+1] == ']'){
				appr--;
			}
			else if(sol[i] == '[' && sol[i+1] == '['){
				appr++;
			}

			if(v[i+1] != appr){
				return false;
			}
		}

		return true;
	};

	int ans=0;
	ans += check(sol1, v) + check(sol2, v);

	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
