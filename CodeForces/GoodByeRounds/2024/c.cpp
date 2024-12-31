#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll recFunc(ll l, ll r, ll k){
	if(l>r) return 0;
	ll len=r-l+1;
	if(len<k) return 0;

	ll m=(l+r)/2;

	ll luckyValue=0;

	 if (len % 2 == 1) {
        luckyValue += m; 
        luckyValue += recFunc(l, m - 1, k);
        luckyValue += recFunc(m + 1, r, k); 
    } else {
        luckyValue += recFunc(l, m, k);
        luckyValue += recFunc(m + 1, r, k);
    }

    return luckyValue;
} 

void solve(){
	ll k, n;
	cin >> n >> k;
	ll ans = recFunc(1, n, k);

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
