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
		int n, m, q;
		cin >> n >> m >> q;
		vi mn(m), qn(q);
		
		for(int i=0; i<m; i++) cin >> mn[i];
		for(int i=0; i<q; i++) cin >> qn[i];

		sort(mn.begin(), mn.end());

		if(qn[0] == mn[0] || qn[0] == mn[1]) cout << "0\n";
		else if(qn[0] > mn[0] && qn[0] < mn[1]){
			cout << (mn[1]-mn[0])/2 << "\n";
		}
		else if(qn[0] < mn[0]) cout << mn[0]-1 << "\n";
		else if(qn[0] > mn[1]) cout << n-mn[1] << "\n";

	}


    return 0;
}
