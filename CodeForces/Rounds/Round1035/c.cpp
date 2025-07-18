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

int log2(int x){
	int ans=0;
	while(x > 1){
		x /= 2;
		ans++;
	}
	return ans;
}

void solve(){
	int n, l, r, k;
	cin >> n >> l >> r >> k;

	if(n==2){
		cout << -1 << "\n";
		return;
	}

	if(n%2!=0){
		cout << l << "\n";
		return;
	}

	int pot = 1LL<<(log2(l)+1);
	if(pot>r){
		cout << -1 << "\n";
		return;
	}

	if(k==n || k==n-1) cout << pot << "\n";
	else cout << l << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}