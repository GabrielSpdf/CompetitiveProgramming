#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<string> ans;
vector<vi> listAdj;
int max_num;

void dfs(int idx, string past){
	if(past!="") ans[idx] = past + to_string(max_num);
	else ans[idx] = ans[idx] + to_string(max_num);
	max_num++;
	
	for(int i=0; i<listAdj[idx].size(); i++){
		dfs(listAdj[idx][i], ans[idx]);
	}

	return;
}

void solve(){
	int n;
	cin >> n;

	ans.clear();
	max_num = 0;

	vector<string> grid(n);
	for(int i=0; i<n; i++){
		cin >> grid[i];
	}
	
	ans = vector<string>(n);
	listAdj = vector<vi>(n);
	vi noincoming;
	vector<bool> noincoming_helper(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j]=='1'){
				listAdj[i].push_back(j);
				noincoming_helper[j] = true;
			}
		}
	}

	for(int i=0; i<n; i++) if(noincoming_helper[i]==false) noincoming.push_back(i);

	for(int i=0; i<noincoming.size(); i++){
		dfs(noincoming[i], "");
	}

	for(int i=0; i<n; i++){
		cout << ans[i].size() << " ";
		cout << ans[i];
		/* for(int j=0; j<ans[i].size(); j++){ */
		/* 	cout << ans[i][j] << " "; */
		/* } */
		cout << "\n";
	}
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
