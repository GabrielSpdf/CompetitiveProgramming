#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	ll x, m;
	cin >> x >> m;

	ll bits=0, x_copy=x;
	while(x_copy>0){
		bits++;
		x_copy/=2;
	}
	
	ll maxfor = min(1LL<<bits,m+1);
	ll ans=0;

	for(int i=1; i<maxfor; i++){
		if(x!=i && (x%(x^i) == 0 || i%(x^i) ==0)){
			ans++;
		}
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
