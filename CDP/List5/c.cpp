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
	string s;
	cin >> s;
	int x;
	int n = (int)s.size();
	cin >> x;
	
	string w = s;
	FORI(0, n) w[i]='1';

	FORI(0, n){
		if(s[i]=='0'){
			if(i-x>=0) w[i-x]='0';
			if(i+x<n) w[i+x]='0';
		}
	}
	
	FORI(0, n){
		if(s[i]=='1'){
			if(i-x>=0 && i+x<n){ 
				if(w[i-x]=='0' && w[i+x]=='0'){ 
					cout << -1 << "\n"; return; 
				}
			}
			else if(i-x>=0){ 
				if(w[i-x]=='0'){ 
					cout << -1 << "\n"; return; 
				}
			}
			else if(i+x<n){ 
				if(w[i+x]=='0'){ 
					cout << -1 << "\n"; return; 
				}
			}
			else{ cout << -1 << "\n"; return; }
		}
	}

	cout << w << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
