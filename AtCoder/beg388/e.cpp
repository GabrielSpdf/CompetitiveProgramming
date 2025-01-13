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

	vll v1, v2;
	for(int i=0; i<n/2; i++) v1.push_back(v[i]);
	for(int i=n/2; i<n; i++) v2.push_back(v[i]);

	int i=0, j=0, ans=0;
	while(i<(int)v1.size() && j<(int)v2.size()){
		cerr << "v1[i]: " << v1[i] << " ";
		cerr << "v2[j]: " << v2[j] << "\n";
		if(v1[i]<=v2[j]/2LL){
			ans++;
			i++; j++;
		}
		else j++;
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
