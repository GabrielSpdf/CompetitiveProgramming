#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n, k;
	cin >> n >> k;

	map<int, int> ans;

	for(int i=0; i<n; i++){
		int inp;
		cin >> inp;
		ans[inp]++;
	}
	
	vi v;
	for(auto nxt: ans){
		v.push_back(nxt.second);
	}

	sort(v.rbegin(), v.rend());
	int idx=v.size()-1;
	while(k>0){
		v[idx]--;
		if(v[idx]==0) idx--;
		k--;
	}	

	int an=0;
	for(int i=0; i<v.size(); i++){
		if(v[i]!=0) an++;
	}

	cout << max(1, an) << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
