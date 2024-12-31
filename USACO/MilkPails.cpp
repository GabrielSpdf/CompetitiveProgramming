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
	int x, y, m;
	cin >> x >> y >> m;

	int ans=0;

	for(int i=0; i<=((m+1)/x); i++){
		for(int j=0; j<=((m+1)/y); j++){
			int temp_ans=0;
			temp_ans+=(i*x)+(j*y);	
			if(temp_ans>m) break;
			else ans=max(ans, temp_ans);
		}
	}

	cout << ans << "\n";
}

int main(){
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
