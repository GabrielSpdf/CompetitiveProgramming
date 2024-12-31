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

	vi m(n), s(n);

	for(auto &a: m) cin >> a;
	for(auto &a: s) cin >> a;

	s.push_back(0);

	int ans=0;
	for(int i=0; i<n; i++){
		if(s[i+1]<m[i]) ans+=abs(m[i]-s[i+1]);
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
