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
		int n, k, ans, ver=0;
		cin >> n >> k;
		vi v(n, 0), bo(101, 0);

		for(int i=0; i<n; i++) cin >> v[i];

		if(n<k) ans=n;
		else{
			for(int i=0; i<n; i++){
				bo[v[i]-1]++;
			}

			for(int i=0; i<101; i++){
				if(bo[i]>=k) ver=1;
			}

			if(ver==1) ans=k-1;
			else ans=n;
		}

		cout << ans << "\n";
	}


    return 0;
}
