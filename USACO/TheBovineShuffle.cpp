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
	vi v(n);
	for(auto &a: v) cin >> a;
	
	vi aft(n);
	for(int i=0; i<n; i++){
		cin >> aft[i];
	}

	vi temp(n);
	for(int i=0; i<3; i++){
		for(int j=0; j<n; j++){
			temp[j] = aft[v[j]-1];
		}
		aft = temp;
	}

	for(int i=0; i<n; i++) cout << temp[i] << "\n";
}

int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
