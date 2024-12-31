#include <bits/stdc++.h>
#include <cstdint>

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
	ll sum=0;
	for(auto &a: v){
		cin >> a;
		sum+=a;
	}
	
	ll ans=INT_FAST32_MAX;
	for(int i=0; i<n; i++){
		int j=0, idx=i;
		ll temp_sum=sum, temp_ans=0;
		while(j<n){
			idx=idx%n;
			temp_sum-=v[idx];
			temp_ans+=temp_sum;
			idx++;
			j++;
		}
		ans = min(ans, temp_ans);
	}
	cout << ans << "\n";
}

int main(){
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
