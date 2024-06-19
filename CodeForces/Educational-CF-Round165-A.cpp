//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	
	int t;
	cin >> t;
	while(t--){
		int n, ans=3;
		cin >> n;
		vi v(n);

		for(int i=0; i<n; i++) cin >> v[i];
		
		for(int i=0; i<n; i++){
			if(i+1 == v[v[i]-1]) ans=2;
		}

		cout << ans << "\n";

	}

    return 0;
}
