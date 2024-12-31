#include <bits/stdc++.h>
#include <climits>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const long long MAX = LONG_LONG_MAX;
const long long MIN = LONG_LONG_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

map<ll, vector<ll>> listAdj;
map<ll, bool> visited;

void dfs(ll req_size){
	if(visited[req_size]) return;

	visited[req_size] = true;
	for(int i=0; i<listAdj[req_size].size(); i++){
		dfs(listAdj[req_size][i]);
	}
}

void solve(){
	int n;
	cin >> n;

	listAdj.clear();
	visited.clear();

	vector<ll> v(n);
	for(auto &a: v) cin >> a;

	vector<ll> pre_size(n);
	for(int i=0; i<n; i++) pre_size[i]=v[i]+i;


	for(int i=0; i<n; i++){
		listAdj[pre_size[i]].push_back(2*pre_size[i]-v[i]);
	}

	dfs(n);

	ll ans=n;
	for(auto i=visited.begin(); i!=visited.end(); i++){
		if((*i).second){
			ans = max(ans, (*i).first);
		}
	}

	cout << ans << "\n";

	/* for(auto i=listAdj.begin(); i!=listAdj.end(); i++){ */
	/* 	cout << (*i).first << ": "; */
	/* 	for(int j=0; j<(*i).second.size(); j++){ */
	/* 		cout << (*i).second[j] << " "; */
	/* 	} */
	/* 	cout << "\n"; */  
	/* } */

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}


