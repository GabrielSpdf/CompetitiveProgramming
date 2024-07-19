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

	while(t--){
		int n;
		cin >> n;
		vi v(n);
		for(auto &a : v) cin >> a;
		
		vi ans, sub;
		ll maior=LLONG_MIN;
		for(int i=0; i<n; i++){
			if(v[i] > maior) maior = v[i];
			else ans.push_back(maior - v[i]);

			if(i>0) sub.push_back(v[i-1] - v[i]);
		}

		if(ans.empty()) cout << *max_element(sub.begin(), sub.end()) << "\n";
		else cout << *max_element(ans.begin(), ans.end()) << "\n";
	}


    return 0;
}
