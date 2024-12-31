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
	vi v(n), ver(100);
	for(auto &a: v) cin >> a;
	
	int score=0;
	for(int i=0; i<n; i++){
		ver[v[i]]++;
	}

	for(int i=0; i<(int)ver.size(); i++){
		if(ver[i]>=2) score+=ver[i]/2;
	}

	cout << score << "\n";
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
