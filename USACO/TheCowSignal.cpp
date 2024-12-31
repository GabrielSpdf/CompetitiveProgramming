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
	int m, n, k;
	cin >> m >> n >> k;
	
	vector<string> vs(m);
	for(int i=0; i<m; i++){
		cin >> vs[i];	
	}

	for(int i=0; i<m; i++){
		for(int t=0; t<k; t++){
			for(int j=0; j<n; j++){
				for(int q=0; q<k; q++){
					cout << vs[i][j];
				}
			}
			cout << "\n";
		}
	}
}

int main(){
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
