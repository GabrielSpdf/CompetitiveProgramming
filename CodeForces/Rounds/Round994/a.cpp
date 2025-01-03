#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n;
	cin >> n;
	vi v(n);
	vector<vi> ans;
	
	int j=0;
	bool emp=true;
	for(int i=0; i<n; i++){
		cin >> v[i];
		if(v[i]!=0 && emp==true){
			emp=false;
			j=i;
		}
		if(v[i]==0 || i==n-1){
			if(emp==false){
				ans.push_back(vi(v.begin()+j, v.end()));
			}
			emp=true;
		}
	}
	cout << min((int)ans.size(), 2) << "\n";

	// 0 0 0 0 0 0
	// 1 1 1 0 1 1
	// 0 1 1 1 1 0
	// 0
	// 1
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
