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

	int n;
	cin >> n;
	int cond, ans=0;
	
	vii v(n);
	for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

	for(int i=0; i<n; i++){
		bool f1=false, f2=false, f3=false, f4=false;
		cond=0;

		for(int j=0; j<n; j++){
			if(i==j) continue;

			if(v[i].first == v[j].first && v[i].second < v[j].second && !f1){ f1=true; cond++; }
			if(v[i].first == v[j].first && v[i].second > v[j].second && !f2){ f2=true; cond++; }
			if(v[i].first < v[j].first && v[i].second == v[j].second && !f3){ f3=true; cond++; }
			if(v[i].first > v[j].first && v[i].second == v[j].second && !f4){ f4=true; cond++; }
		}
		if(cond==4) ans++;
	}

	cout << ans << "\n";


    return 0;
}
