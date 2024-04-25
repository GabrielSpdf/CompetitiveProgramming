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

	//5 / 2 = 2.5 = 3 idx
	//4 / 2 = 2 idx
	
	int t;
	cin >> t;
	while(t--){
		int n, idx, count=1;
		cin >> n;

		vector<ll> v(n);

		for(int i=0; i<n; i++){
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		idx = ((int)v.size()+1)/2;
		idx--;

		for(int i=0; i<(int)v.size(); i++){
			if(i>idx){
				if(v[i]==v[idx]) count++;
			}
		}

		cout << count << "\n";
	}

    return 0;
}

