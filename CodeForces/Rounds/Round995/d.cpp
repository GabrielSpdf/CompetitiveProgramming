#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll countPairs(vector<ll>&v, ll limit){
	ll count=0;
	ll l=0, r=v.size()-1;

	while(l<r){
		if(v[l]+v[r]>limit) r--;
		else{
			count+=(r-l);
			l++;
		}
	}

	return count;
}

void solve(){
	ll n, x, y;
	cin >> n >> x >> y;

	vector<ll> v(n);
	ll sum=0;
	for(auto &a: v){
		cin >> a;
		sum+=a;
	}

	sort(v.begin(), v.end());

	ll inc = countPairs(v, sum-x);
	ll rem = countPairs(v, sum-y+1);

	cout << inc-rem << "\n";
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
