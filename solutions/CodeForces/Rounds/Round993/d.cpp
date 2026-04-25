#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	cin >> n;
	vi v(n);

	for(auto &a : v) cin >> a;

	vi ans(n, 0);
	
	vi app;
	for(int i=0; i<n; i++){
		if(ans[v[i]-1] == 0){
			ans[v[i]-1]=v[i];
			app.push_back(v[i]);
		}
	}
	
	vi not_app;
	for(int i=0; i<n; i++){
		if(ans[i]==0) not_app.push_back(i+1);
	}

	int it=app.size();

	for(int i=0; i<it; i++){
		cout << app[i] << " ";
	}

	for(int i=0; i<(n-it); i++){
		cout << not_app[i] << " ";
	}

	cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
