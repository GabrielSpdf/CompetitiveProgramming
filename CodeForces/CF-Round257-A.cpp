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

	int n, m;

	cin >> n >> m;

	vi v(n);
	for(auto &a:v) cin >> a;

	int ver=0, ans, i=0;
	for(int i=0; i<n; i++){
		v[i]-=m;

		if(v[i]<=0){
			if(v[i]!=INF){
				v[i]=INF;
				ver++;
			}
		}

		ans = i;

		if(ver==n) break;

		if(i==(n-1)) i=-1;
	}

	cout << ans+1 << "\n";


    return 0;
}
