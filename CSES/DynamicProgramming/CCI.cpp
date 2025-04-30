#include <bits/stdc++.h>

// runtimeerror no cses mas localmente funciona
// entender oq gera esse runtimeerror

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

#define mod 1000000007

void solve(){
	int n, x;
	cin >> n >> x;

	vi coins(n);
	for(auto &a: coins) cin >> a;
	
	vvi v(n+1, vi(x+1));
	FORI(0, n+1){
		FORJ(0, x+1){
			v[i][j]=0;
		}
	}

	FORI(0, n){
		if(coins[i]<=x){
			v[i][coins[i]] = 1;
			/* v[n][coins[i]] = 1; */
		}
	}
	
	FORI(0, x+1){
		FORJ(0, n){
			if((i-coins[j])>=0) v[j][i] = (v[j][i]+v[n][i-coins[j]]) % mod;
			v[n][i] = (v[j][i]+v[n][i]) % mod;
		}
	}

	/* tvvi(v); */
	/* cout << v[n][x] % mod << "\n"; */
	cout << v[n][x] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
