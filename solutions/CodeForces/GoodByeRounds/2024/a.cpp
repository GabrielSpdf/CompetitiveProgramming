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
	int n;
	cin >> n;
	vi v(n);
	for(auto &a: v) cin >> a;
	
	bool ans = false; 
	for(int i = 0; i + 1 < n; i++){
		long long mn = min(v[i], v[i+1]);
		long long mx = max(v[i], v[i+1]);
		if(2LL * mn > mx){
			ans = true;
			break;
		}
	}
	
	if(ans) cout << "YES\n";
	else cout << "NO\n";
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
