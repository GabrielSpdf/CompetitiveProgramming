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
	int n, k, inp1, inp2;
	ll ans=0, total=0;
	cin >> n >> k;

	vi v(k+2);

	for(int i=0; i<k; i++){
		cin >> inp1 >> inp2;
		v[inp1]+=inp2;
		total+=inp2;
	}

	sort(v.rbegin(), v.rend());

	if(v.size()<n) ans=total;
	else{
		for(int i=0; i<n; i++){
			ans+=v[i];
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
