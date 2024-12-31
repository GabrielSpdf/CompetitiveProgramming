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

	for(auto &a: v) cin >> a;

	vi pre(n);
	pre[0] = v[0];
	for(int i=1; i<n; i++) pre[i]=max(pre[i-1], v[i]);

	vii pos(n);
	pos[n-1] = make_pair(n-1, v[n-1]);
	for(int i=n-2; i>=0; i--){
		if(pos[i+1].second < v[i]) pos[i]=pos[i+1];
		else pos[i]=make_pair(i, v[i]);
	}

	for(int i=0; i<n; i++){
		cout << "i # v[i]: " << i << " # " << v[i] << "\n";
		cout << "pre[i]: " << pre[i] << "\n";
		cout << "pos[i].first: " << pos[i].first << "\n";
		cout << "pos[i].second: " << pos[i].second << "\n";
		if(v[i]>pos[i].second) cout << pre[pos[i].first] << " ";
		else cout << pre[i] << " ";
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
