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

vector<vi> listAdj;

void solve(){
	int n;
	cin >> n;
	listAdj = vector<vi>(n);
	for(int i=0; i<(n-1); i++){
		int a, b;
		cin >> a >> b; a--; b--;
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}

	int ans=0;
	for(int i=0; i<n; i++){
		ans = max(ans, (int)listAdj[i].size());
	}

	cout << ans+1 << "\n";
}

int main(){
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
