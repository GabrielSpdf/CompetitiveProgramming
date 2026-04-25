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
	int n, k;
	cin >> n >> k;

	vi v(n);
	for(auto &a: v) cin >> a;
	
	bool flag=false;
	for(int i=0; i<n; i++){
		flag=false;
		for(int j=0; j<n; j++){
			if(i==j) continue;
			if(abs(v[i]-v[j])%k==0){
				flag=true;
			}
		}
		if(flag==false){
			cout << "YES\n";
			cout << i+1 << "\n";
			return;
		}
	}

	cout << "NO\n";
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
