// Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v(n);
		for(auto &a: v) cin >> a;

		ll ans = v[v.size()-1], sum=v[v.size()-2];
		for(int i=(int)v.size()-3; i>=0; i--){
			sum-=v[i];
		}

		cout << ans - sum << "\n";
	}


    return 0;
}
