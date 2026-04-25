// Not solved yet

#include <algorithm>
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

	map<int, ii> mp;
	vi v(n);
	FORI(0, n) cin >> v[i];
	
	mp[v[v.size()-1]] = make_pair(v[v.size()-1]+1, n);

	for(int i=n-2; i>=0; --i){
		if(mp.find(v[i]+1)==mp.end()){
			mp[v[i]] = make_pair(v[i]+1, i+1);
		}
		else{
			mp[v[i]] = mp[v[i+1]];
		}
	}
	
	int x=1, j=mp[x].second;
	FORI(0, k){
		if(mp.find(x)!=mp.end()){
			auto it = --mp.lower_bound(mp[x].first+mp[x].second);
			j = (*it).second.second;
		}
		else if(mp.find(x+j)!=mp.end()){
			auto it = --mp.lower_bound(mp[x+j].first+mp[x+j].second);
			j = (*it).second.second;
		}
		x+=j;
		cerr << x << " ";
	}
	cout << x << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
