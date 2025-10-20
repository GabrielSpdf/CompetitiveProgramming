#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int n, k;
	cin >> n >> k;
	vi v(n);
	map<int, int> freq;
	for(auto &a: v){
		cin >> a;
		freq[a]++;
	}

	for(auto& [a, b]: freq){
		if(b%k){
			cout << "0\n";
			return;
		}
		b/=k;
	}

	int l=0, r=0, ans=0;
	map<int, int> cur_freq;
	while(r>=l && r<n){
		cur_freq[v[r]]++;

		while(cur_freq[v[r]] > freq[v[r]]){
			cur_freq[v[l]]--;
			l++;
		}

		ans+=(r-l+1);
		r++;
	}

	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
