#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	vi vn(n);
	for(auto &a: vn) cin >> a;
	vi vm(m);
	for(auto &a: vm) cin >> a;
	
	// ordenacao 
	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());

	// prefix sum
	vi pfn(n+1, 0), pfm(m+1, 0);
	for(int i=1; i<n+1; i++){
		pfn[i] = pfn[i-1] + vn[i-1];
	}
	for(int i=1; i<m+1; i++){
		pfm[i] = pfm[i-1] + vm[i-1];
	}
	
	// queries
	while(q--){
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		// xi -> vn
		// yi -> vm
		
		int l = max(0ll, zi-yi), r = min(xi, zi);

		auto f = [&](int k){
			return (pfn[n]-pfn[n-k])+(pfm[m]-pfm[m-(zi-k)]);
		};

		while(r - l >= 3){
			int mid1 = l + (r-l)/3;
			int mid2 = r - (r-l)/3;
			
			int f1 = f(mid1);
			int f2 = f(mid2);

			if(f1 < f2){
				l = mid1;
			}
			else{
				r = mid2;
			}
		}

		int ans = 0;
		for(int k=l; k<=r; k++){
			ans = max(ans, f(k));
		}

		cout << ans << "\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
