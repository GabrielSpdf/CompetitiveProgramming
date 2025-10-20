#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int n;
	cin >> n;
	vi v(n), odd, even;
	for(auto &a: v){
		cin >> a;
		if(a%2) odd.push_back(a);
		else even.push_back(a);
	}
	sort(odd.begin(), odd.end());

	int ans = 0;
	if(odd.size()>0){
		for(int i=0; i<even.size(); i++)
			ans+=even[i];
		
		int i=0, j=odd.size()-1;
		while(i<=j){
			// menor idx -> menor valor
			ans+=odd[j];
			i++;
			j--;
		}
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
