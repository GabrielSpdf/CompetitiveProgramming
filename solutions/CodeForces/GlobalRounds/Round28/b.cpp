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
	vi v(n);	
	
	int mn=1;
	for(int i=k-1; i<n; i+=k){
		v[i]=mn++;	
	}
	for(int i=0; i<n; i++){
		if(v[i]==0) v[i]=mn++; 
	}

	for(int i=0; i<n; i++) cout << v[i] << " ";
	cout << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
