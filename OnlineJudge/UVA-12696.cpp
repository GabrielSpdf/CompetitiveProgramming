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

	int t, sum=0;
	cin >> t;
	while(t--){
		double l, w, d, wgt;
		cin >> l >> w >> d >> wgt;

		if(((l<=56.0 && w<=45.0 && d<=25.0) || (l+w+d)<=125.0) && wgt<=7.0) { cout << "1\n"; sum++; }
		else cout << "0\n";
	}

	cout << sum << "\n";


    return 0;
}
