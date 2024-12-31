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
	int fn = 1, fsn=14;
	if(n%2) if(n<27) cout << -1; else{ cout << "1 2 2 3 3 4 4 5 5 1 13 6 6 7 7 8 8 9 9 10 10 11 11 12 12 1 13 "; for(int i=0; i<(n-27); i++) if(i%2) cout << fsn++ << " "; else cout << fsn << " "; }

	else for(int i=0; i<n; i++) if(i%2) cout << fn++ << " "; else cout << fn << " "; 
	cout << "\n";
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
