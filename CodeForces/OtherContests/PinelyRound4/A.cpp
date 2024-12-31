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
		int n, maior=-1;
		cin >> n;
		vi v(n);
		for(auto &a: v) cin >> a;

		for(int i=0; i<n; i++){
			if(i%2==0) if(v[i]>maior) maior=v[i];
		}

		cout << maior << "\n";
	}


    return 0;
}
