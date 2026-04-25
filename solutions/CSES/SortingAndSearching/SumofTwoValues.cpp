#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<int, int> find_n(vector<int> v, int n1, int n2){
	int fst, snd;
	bool fnd_fst=false, fnd_snd=false;
	for(int i=0; i<(int)v.size(); i++){
		if(v[i] == n1 && !fnd_fst){
			fnd_fst = true;
			fst = i+1;
		}
		else if(v[i] == n2 && !fnd_snd){
			fnd_snd = true;
			snd = i+1;
		}
	}

	return make_pair(fst, snd);
}

void solve(){
	int n, target;

	cin >> n >> target;
	vector<int> v(n), vaux;
	for(auto &a: v) cin >> a;

	vaux = v;
	sort(v.begin(), v.end());

	int i=0, j=n-1;
	while(i<j){
		int sum = v[i]+v[j];
		if(sum==target){
			pair<int, int> ans = find_n(vaux, v[i], v[j]);
			if(ans.first > ans.second){
				swap(ans.first, ans.second);
			}
			cout << ans.first << " " << ans.second << "\n";
			return;
		}
		else if(sum>target){
			j--;
		}
		else{
			i++;
		}
	}
	cout << "IMPOSSIBLE\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
