#include <bits/stdc++.h>
#include <climits>

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
	vi v(n);
	FORI(0, n) cin >> v[i];
	v[0] = 1;
	
	if(n==k){
		for(int i=1; i<n; i+=2){
			if(v[i]!=(i+1)/2){
				cout << (i+1)/2 << "\n";
				return;
			}
		}
		cout << k/2+1 << "\n";
		return;
	}
	int idx=LLONG_MAX;
	for(int i=0; i<n; i++){
		if(v[i]!=1){
			idx=i+1;
			break;
		}
	}
	if(n-idx+2 >= k){
		cout << 1 << "\n";
		return;
	}
	cout << 2 << "\n";
	return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
