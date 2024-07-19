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

	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		int n, high=0, low=0;
		cin >> n;
		vi v(n);
		for(int j=0; j<n; j++) cin >> v[j];

		for(int j=1; j<n; j++){
			if(v[j]<v[j-1]) low++;
			if(v[j]>v[j-1]) high++;
		}

		cout << "Case " << i << ": " << high << " " << low << "\n";
	}


    return 0;
}
