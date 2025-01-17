#include <algorithm>
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

	set<int> temp;
	for(int i=0; i<n; i++){
		int inp1;
		cin >> inp1;
		temp.insert(inp1);
	}

	vi v(temp.begin(), temp.end());
	map<int, int> ans;

	for(int i=0; i<n; i++){
		ans[i] = *lower_bound(v.begin(), v.end(), v[i]+n-1);
	}

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
