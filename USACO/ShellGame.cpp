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
	
	vector<tuple<int, int, int>> vt;
	for(int i=0; i<n; i++){
		int a, b, g;
		cin >> a >> b >> g;
		vt.push_back(tuple<int, int, int>(a, b, g));
	}

	int ans=0;

	// if is in 1
	int cur=1, points=0;
	for(auto [a, b, g] : vt){
		if(a == cur) cur=b;
		else if(b == cur) cur=a;

		if(g == cur) points++;
	}

	ans=max(ans, points);

	// if is in 2
	cur=2, points=0;
	for(auto [a, b, g] : vt){
		if(a == cur) cur=b;
		else if(b == cur) cur=a;

		if(g == cur) points++;
	}


	ans=max(ans, points);

	// if is in 3
	cur=3, points=0;
	for(auto [a, b, g] : vt){
		if(a == cur) cur=b;
		else if(b == cur) cur=a;

		if(g == cur) points++;
	}

	ans=max(ans, points);

	cout << ans << "\n";
}

int main(){
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
