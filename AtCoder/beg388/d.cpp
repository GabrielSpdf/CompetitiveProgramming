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

void solve(){
	int n;
	cin >> n;
	vll v(n);
	for(auto &a: v) cin >> a;

	vll pfs(n+1, 0);
	
	int cnt=0;
	for(int i=0; i<n; i++){
		cnt+=pfs[i];
		v[i]+=cnt;
		if(v[i]>0){
			int bgn = i+1;
			int end = bgn+v[i];
			pfs[min(bgn, (int)v.size())]++;
			pfs[min(end, (int)v.size())]--;
		}
	}
	
	vll ans(n);
	for(int i=0; i<n; i++){
		/* cnt+=pfs[i]; */
		/* v[i]+=cnt; */
		/* cerr << v[i] << " "; */
		ans[i] = max(v[i]-((int)v.size()-(i+1)), 0LL);
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
