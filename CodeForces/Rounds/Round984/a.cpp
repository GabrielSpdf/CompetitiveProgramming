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
	string ans="YES";
	cin >> n;
	vi v(n);
	for(auto &a: v) cin >> a;

	for(int i=0; i<(n-1); i++){
		if(abs(v[i]-v[i+1])!=5 && abs(v[i]-v[i+1])!=7){ ans="NO"; break; }
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
