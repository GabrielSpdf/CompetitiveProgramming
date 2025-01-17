// Unsolved yet

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(n) for(int i=0; i<(n); i++)
#define FORJ(n) for(int j=0; j<(n); j++)
#define FORK(n) for(int k=0; k<(n); k++)
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

void solve(){
	int n;
	cin >> n;
	vi v(n);
	FORI(n) cin >> v[i];

	int ans=0;
	for(int i=1; i<=n; i++) if(i%2) ans+=i;
	
	map<int, int> qtd;
	for(int i=0; i<n; i++){
		qtd[v[i]]++;
	}
	
	for(auto nxt:qtd){
		if(nxt.second>2 && nxt.second%2==0){
			ans += (nxt.second%2 == 0 ? nxt.second*(nxt.second+2)/4 : (nxt.second+1)*(nxt.second+1)/4);
		}
	}

	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
