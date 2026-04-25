#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI((v).size()) cerr << (v)[i] << " "; cerr << "\n";
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

	int idx=0, value=0;
	vi pfs(1, 0);
	FORI(0, n){
		int inp1;
		cin >> inp1;
		
		/* FORI(0, pfs.size()) cerr << pfs[i]-value << " "; */
		/* cerr << "\n"; */
		if(inp1!=2){
			int inp2;
			cin >> inp2;
			if(inp1==1){
				pfs.pb(pfs[pfs.size()-1]+inp2);
			}
			if(inp1==3){
				if(pfs[inp2-1+idx]-value>=0) cout << pfs[inp2-1+idx]-value << "\n";
			}
		}
		else{
			/* cerr << "value: " << value << "\n"; */
			value+=pfs[1+idx]-value;
			/* cerr << "value: " << value << "\n"; */
			idx++;
		}
	}

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
