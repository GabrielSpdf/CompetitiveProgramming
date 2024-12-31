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
	int n, m;
	cin >> n >> m;
	
	vii qn(n), qm(m);
	vi road(100), cur(100);
	int past=0;
	for(auto &a: qn){
		cin >> a.first >> a.second;
		fill(road.begin()+past, road.begin()+past+a.first, a.second);
		past = past+a.first;
	}
	past=0;
	for(auto &a: qm){
		cin >> a.first >> a.second;
		fill(cur.begin()+past, cur.begin()+past+a.first, a.second);
		past = past+a.first;
	}
	
	int ans=0;
	for(int i=0; i<100; i++){
		/* cout << "road[" << i << "]: " << road[i] << " & cur[" << i << "]: " << cur[i] << "\n"; */
		ans=max(ans, max(0, cur[i]-road[i]));
	}

	cout << ans << "\n";
}

int main(){
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
