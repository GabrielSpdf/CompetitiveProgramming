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

int sol(vi &teach, int low, int high, int d, int n){
	bool antes=false, depois=false;
	int tbef, taft;

	while(low <= high){
		int mid = low + (high-low) / 2;

		if(teach[mid] == d)
			return 0;
		if(teach[mid] < d){
			tbef = teach[mid];
			low = mid + 1;
			antes = true;
		}
		else{
			taft = teach[mid];
			high = mid - 1;
			depois = true;
		}
	}	

	if(antes && depois){
		return (taft-tbef)/2;
	}
	else if(antes){
		return n-tbef;
	}
	else if(depois){
		return taft-1;
	}

	return -1;
}

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

		for(int i=0; i<q; i++){
			cout << sol(mn, 0, m-1, qn[i], n) << "\n";
		}
	}


    return 0;
}

