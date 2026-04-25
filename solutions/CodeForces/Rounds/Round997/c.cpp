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
	
	vi v(n, 0);
	if(n==6){
		v = {1, 1, 2, 3, 1, 2};
	}
	else{
		v[0] = 1;
		v[1] = 2;
		v[n-1] = 2;
		v[n-2] = 1;
		for(int i=2; i<n-2; i++){
			v[i] = i+1;
		}
	}

	FORI(n) cout << v[i] << " ";
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
