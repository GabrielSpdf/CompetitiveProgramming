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
	ll n;
	cin >> n;

	if(n <= 3) cout << 1 << "\n";
	else{
		ll ans=1;
		while(n>3){
			ans*=2;
			n/=4;
		}
		cout << ans << "\n";
	}

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
