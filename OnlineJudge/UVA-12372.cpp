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
		int l, w, h;
		cin >> l >> w >> h;
		
		cout << "Case " << i << ": ";

		if(l > 20 || w > 20 || h > 20) cout << "bad\n";
		else cout << "good\n";
	}



    return 0;
}
