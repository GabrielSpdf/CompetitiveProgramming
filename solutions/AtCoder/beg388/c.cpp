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

void solve(){
	int n;
	cin >> n;
	
	vll v(n);
	
	for(auto &a: v) cin >> a;

	ll ans=0;
	ll i=v.size()-1, j=v.size()-1;
	while(i>=0 && j>=0){
		if(v[j]<=v[i]/2){
			ans+=j+1;
			i--;
		}
		else{
			j--;
		}
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
