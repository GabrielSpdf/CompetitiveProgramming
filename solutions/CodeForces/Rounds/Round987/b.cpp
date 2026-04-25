// Accepted

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
	vii ans;

	for(auto &a: v) cin >> a;
	
	ll menor=MAX, maior=MIN, menor_idx, maior_idx;
	for(int i=0; i<n; i++){
		if(v[i]>maior){ maior=v[i]; maior_idx=i; }
		if(v[i]<menor){ menor=v[i]; menor_idx=i; }
		if(i%2){
			if(menor_idx > maior_idx && abs(maior-menor)!=1){ 
				cout << "NO\n"; 
				return; 
			}
			ans.emplace_back(make_pair(menor, maior));
			menor=MAX, maior=MIN;
		}
	}
	if(n%2) ans.emplace_back(make_pair(menor, maior));
	
	string out="YES";
	for(int i=0; i<(int)ans.size()-1; i++){
		if(ans[i].second > ans[i+1].first && abs(ans[i].second - ans[i+1].first)!=1){ out="NO"; break; }
	}

	cout << out << "\n";
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
