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
		int n, ans, maxf=INT_MIN, maxs=INT_MIN;
		cin >> n;
		vi f(n), s(n);

		for(int i=0; i<n; i++){
			cin >> f[i] >> s[i];
			if(f[i]>maxf) maxf=f[i];
			if(s[i]>maxs) maxs=s[i];
		}
		
		cout << (maxf+maxs)*2 << "\n";
	}

    return 0;
}

