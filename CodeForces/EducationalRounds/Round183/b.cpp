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
	string s;
	cin >> s;

	vector<char> v(n, '+');

	int tp=0, bt=0, uk=0;
	for(int i=0; i<(int)s.size(); i++){
		if(s[i]=='0'){
			tp++;
		}
		if(s[i]=='1'){
			bt++;
		}
		if(s[i]=='2'){
			uk++;
		}
	}
	
	int last_tp=n-1-tp, last_bt=max(0ll, bt-1);
	for(int i=0; i<tp; i++){
		v[n-1-i]='-';
	}
	for(int i=0; i<bt; i++){
		v[i]='-';
	}

	while(uk>0 && last_bt<=last_tp){
		v[last_bt]='?';
		v[last_tp]='?';
		last_tp--;
		last_bt++;
		uk-=2;
	}

	for(auto &a: v) cout << a;
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
