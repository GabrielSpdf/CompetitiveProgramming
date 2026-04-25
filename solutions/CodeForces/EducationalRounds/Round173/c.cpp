#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int64_t MIN = INT64_MIN;
const int64_t MAX = INT64_MAX;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<ll> v;
set<ll> ans;

pair<ll, ll> ans_subarray(ll init, ll end){
	ll maior=0, menor=0, cur_max=0, cur_min=0, cur=0, past=0;

	for(int i=init; i<end; i++){
		cur+=v[i];
		if(cur>past){
			cur_max+=v[i];
			cur_min=min(0LL, cur_min+v[i]);
		}
		else{
			cur_max=max(0LL, cur_max+v[i]);
			cur_min+=v[i];
		}
		if(cur_min<menor) menor=cur_min;
		if(cur_max>maior) maior=cur_max;
		past=cur;
	}
	
	return make_pair(menor, maior);
}

void solve(){
	int n;
	cin >> n;
	
	v.clear();
	ans.clear();
	v = vector<ll>(n);

	ll l1=0, l2=n, r1=0, r2=n, special_idx;
	bool isX = false;
	for(int i=0; i<n; i++){
		cin >> v[i];
		if(v[i]!=1 && v[i]!=-1){
			isX = true;
			special_idx=i;
			l2= i;	
			r1=min(n, i+1);
		}
	}
	
	pair<ll, ll> sa1 = ans_subarray(l1, l2);		
	pair<ll, ll> sa2 = ans_subarray(r1, r2);		

	for(ll i=sa1.first; i<=sa1.second; i++){
		ans.insert(i);
	}

	for(ll i=sa2.first; i<=sa2.second; i++){
		ans.insert(i);
	}

	if(isX){
		vector<ll> prefixL, prefixR;
		prefixL.push_back(0);
		prefixR.push_back(0);
		
		int idx=0;
		for(int i=special_idx+1; i<n; i++){
			prefixR.push_back(prefixR[idx]+v[i]);
			idx++;
		}

		idx=0;
		for(int i=special_idx-1; i>=0; i--){
			prefixL.push_back(prefixL[idx]+v[i]);
			idx++;
		}

		ll min1 = *min_element(prefixR.begin(), prefixR.end());
		ll min2 = *min_element(prefixL.begin(), prefixL.end());
		ll max1 = *max_element(prefixR.begin(), prefixR.end());
		ll max2 = *max_element(prefixL.begin(), prefixL.end());

		/* cout << "min1: " << min1 << "\n"; */
		/* cout << "min2: " << min2 << "\n"; */
		/* cout << "max1: " << max1 << "\n"; */
		/* cout << "max2: " << max2 << "\n"; */

		ll global_min = min1+min2+v[special_idx];
		ll global_max = max1+max2+v[special_idx];

		for(int i=global_min; i<=global_max; i++){
			ans.insert(i);
		}
	}

	cout << ans.size() << "\n";
	for(auto i=ans.begin(); i!=ans.end(); i++){
		cout << (*i) << " ";
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
// te amo
