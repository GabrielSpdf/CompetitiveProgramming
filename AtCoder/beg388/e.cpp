// Unsolved yet

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
	vector<bool> used(n, false);
	while(i>=0 && j>=0){
		cerr << "v[i]: " << v[i] << " ";
		cerr << "v[j]: " << v[j] << " ";
		cerr << "v[i]/2: " << v[i]/2 << "\n";
		if(used[i]) i--;
		else if(used[j]) j--;
		else{
			if(v[j]<=v[i]/2){
				cerr << v[i] << " with " << v[j] << "\n";
				used[i]=true;
				used[j]=true;
				ans++;
				i--;
				j--;
			}
			else{
				j--;
			}
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
