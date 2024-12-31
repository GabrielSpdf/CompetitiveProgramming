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
	int n, m, k;
	string s;
	cin >> n >> m >> k >> s;
	
	int adj=0, dontworry=-1, res=0;
	for(int i=0; i<(int)s.size(); i++){
		if(dontworry>(int)s.size()) break;

		if(s[i] =='0' && i>dontworry){
			adj++;
			if(adj == m){
				dontworry = i+k-1;
				res++;
				adj=0;
			}
		}
		else adj=0;
	}

	cout << res << "\n";
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
