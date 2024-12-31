// Accepted

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

	int n;
	cin >> n;

	vi v(7);
	for(auto &a : v) cin >> a;

	int i=0;
	while(n>0){
		if(i==7) i=0;

		n -= v[i];
		if(n<=0){ cout << ++i << "\n"; break; }

		i++;
	}

    return 0;
}
