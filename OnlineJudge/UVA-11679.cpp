//Accepted

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

	int b, n;
	cin >> b >> n;
	while(b != 0 && n != 0){
		vi r(b), d(n), c(n), v(n);

		for(auto &a : r) cin >> a;

		for(int i=0; i<n; i++){
			cin >> d[i] >> c[i] >> v[i];

			r[d[i]-1] -= v[i];
			r[c[i]-1] += v[i];
		}

		if(*min_element(r.begin(), r.end()) >= 0) cout << "S\n";
		else cout << "N\n";


		cin >> b >> n;
	}



    return 0;
}
