//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, a, b;

		cin >> n >> a >> b;

		int ans1, ans2;
		ans1 = a*n;
		ans2 = (n/2)*b + (n-(2*(n/2)))*a;

		cout << min(ans1, ans2) << "\n";
	}


	return 0; 
}
