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

	sort(v.begin(), v.end());
	
	int fp=0, lp=n-1;

	int ans=v[fp]*v[lp];

	while(ans!=(n-2)){
		if(ans>(n-2))lp--;
		else if(ans<(n-2)) fp++;
		else break;

		ans=v[fp]*v[lp];
	}

	cout << v[fp] << " " << v[lp] << "\n";
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
