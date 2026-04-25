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

bool isValid(int a, int b, int r){
	return (2*a+1)*(2*a+1)+(2*b+1)*(2*b+1) <= 4*(r*r);
}

void solve(){
	int r;
	cin >> r;

	int ans=(4*(r-1))+1; // caso base
	int cnt=0;
	int up = r-1;

	for(int i=1; isValid(i, 1, r); i++){ // para todo i que eh valido 
		while(!isValid(i, up, r)) --up;	 // ajusta o up para tambem ser valido
		cnt += up; // adiciona o up
	}

	ans += 4*cnt;
	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
