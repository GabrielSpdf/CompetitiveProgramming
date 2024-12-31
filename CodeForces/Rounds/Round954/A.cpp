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
		vi x(3);
		for(int i=0; i<3; i++){
			cin >> x[i];
		}

		sort(x.begin(), x.end());

		cout << abs(x[1]-x[0]) + abs(x[1]-x[2]) << "\n";
	}


    return 0;
}
