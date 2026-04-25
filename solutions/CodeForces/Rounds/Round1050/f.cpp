#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void ap_cands(string &ans, vector<string>& cands){
	if(cands.size() == 0){
		return;
	}

	vector<string> aux;
	sort(cands.begin(), cands.end());
	int tam = cands[0].size();
	ans+=cands[0];

	for(int i=0; i<cands.size(); i++){
		if(cands[i].size()>ans.size()){
			aux.push_back(cands[i].substr(ans.size()));
		}
	}
	ap_cands(ans, aux);
}

void solve(){
	int n;
	cin >> n;
	string ans="A";
	map<int, vector<string>> mp;
	map<int, vi> mpi;

	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		string s="";
		for(int j=0; j<k; j++){
			int num;
			cin >> num;
			mpi[k].push_back(num);
			s+=to_string(num);
		}
		mp[s.size()].push_back(s);
		if(s<ans){
			ans = s;
		}
	}

	int tam = ans.size();
	vector<string> cands;
	for(auto [a, b]: mp){
		if(a>tam){
			for(auto s: b){
				cands.push_back(s.substr(tam));
			}
		}
	}
	ap_cands(ans, cands);

	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
