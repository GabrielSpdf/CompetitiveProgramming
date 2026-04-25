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
	int a, b;
	cin >> a >> b;
	
	int res=lcm(a,b);
	int minimo = min(a, b);
	for(int i=minimo; i<lcm(a, b); i+=minimo){
		if((i%a) == (i%b)){ res=i; break; }
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
