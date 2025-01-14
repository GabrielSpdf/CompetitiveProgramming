#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

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

void solve(){
	int n;
	cin >> n;

	vll v(n);
	for(auto &a: v) cin >> a;
	
	map<ll, vll> ans;
	for(int i=0; i<n; i++){
		ans[i-v[i]].pb(v[i]);
	}
	
	ll otp=0;
	for(auto &nxt: ans) sort(nxt.second.rbegin(), nxt.second.rend());

	for(auto nxt: ans){
		for(int i=1; i<nxt.second.size(); i+=2){
			ll value = nxt.second[i]+nxt.second[i-1];
			if(value >= 0) otp+=value;
			else break;
		}
	}

	cout << otp << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
