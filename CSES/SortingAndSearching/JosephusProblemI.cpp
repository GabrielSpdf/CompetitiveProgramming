// Not solved yet

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
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

void vprint(vi& v1, vi& v2){
	FORI(0, v1.size()){ cout << v1[i] << " "; }
	FORI(0, v2.size()){ cout << v2[i] << " "; }
}

void solve(){
	int n;
	cin >> n;
	vi v(n);
	iota(v.begin(), v.end(), 1);
	
	vi three_odd, one_odd;
	int idx=0, jump=4;
	while(idx<n){
		one_odd.pb(v[idx]);
		idx+=jump;
	}
	idx=2;
	jump+=2;
	while(idx<n){
		three_odd.pb(v[idx]);
		idx+=jump;
	}
	
	FORI(0, n) if(!(v[i]%2)) cout << v[i] << " ";
	if(n%2) vprint(one_odd, three_odd);
	else vprint(three_odd, one_odd);
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
