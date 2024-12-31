#include <bits/stdc++.h>
#include <tuple>

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
	vector<tuple<int, int, int>> vt(n);
	for(int i=0; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		vt[i] = make_tuple(a, b, c);
	}

	vi ps(1123, 0);
	for(auto [si, ti, bi] : vt){
		for(int i=si; i<ti; i++){
			ps[i]+=bi;
		}	
	}
	
	int ans=0;
	for(int i=0; i<ps.size(); i++){
		ans = max(ans, ps[i]);
	}

	cout << ans << "\n";
}

int main(){
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
