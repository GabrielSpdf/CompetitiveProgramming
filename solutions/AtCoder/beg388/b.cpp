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

int wgt(vpii v, int sum){
	int mx=INT_MIN;
	for(int i=0; i<v.size(); i++){
		int res = v[i].first*(v[i].second+sum);
		mx = max(mx, res);
	}
	return mx;
}

void solve(){
	int N, D;
	cin >> N >> D;

	vpii v(N);
	for(int i=0; i<N; i++){
		int inp1, inp2;
		cin >> inp1 >> inp2;
		v[i] = make_pair(inp1, inp2);
	}

	for(int j=1; j<=D; j++){
		cout << wgt(v, j) << "\n";
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
