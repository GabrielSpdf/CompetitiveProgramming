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
		int n, i, j, k, l;
		cin >> n;
		vector<ll> v(n);


		for(int i=0; i<n; i++){
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		i = v[v.size()-1];
		k = v[v.size()-2];
		j = v[0];
		l = v[1];


		cout << abs(i-j)+abs(j-k)+abs(k-l)+abs(l-i) << "\n";


	}


    return 0;
}
