#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void solve(){
	int n;
	cin >> n;
	
	vi vx(n), vy(n);
	for(auto &a: vx) cin >> a;
	for(auto &a: vy) cin >> a;
	
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int dx = vx[i] - vx[j];
			int dy = vy[i] - vy[j];
			int dist = (dx*dx)+(dy*dy);
			ans = max(ans, dist);
		}
	}

	cout << ans << "\n";
}

int main(){
	/* freopen("problename.in", "r", stdin); */
	/* freopen("problename.out", "w", stdout); */

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
