#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

vi countAlp(string s){
	vi v(26, 0);
	for(int i=0; i<(int)s.size(); i++){ //O(10)
		v[s[i]-0x61]++;
	}

	return v;
}

vi compV(vi v1, vi v2){ //O(26)
	vi v(26, 0);
	for(int i=0; i<26; i++){
		v[i]=max(v1[i], v2[i]);
	}

	return v;
}

void solve(){
	int n;
	cin >> n;

	vector<vi> v;
	for(int i=0; i<n; i++){ // O(100*10*10*26) -> O(260000)
		string a, b;
		cin >> a >> b;
		
		vi va = countAlp(a);
		vi vb = countAlp(b);
		v.push_back(compV(va, vb));
	}
	
	vi ans(26, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++){
			ans[j]+=v[i][j];
		}
	}

	for(int i=0; i<26; i++){
		cout << ans[i] << "\n";
	}
}

int main(){
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
